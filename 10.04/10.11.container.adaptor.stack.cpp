#include <cassert>
#include <cmath>
#include <iterator>
#include <stack>
#include <utility>
#include <array>

/////////////////////////////////////////////////////////////////////////////////////

template < typename T > class Stack_v1
{
public:

    void push(T x)
    {
        auto max = std::empty(m_data) ? x : std::max(x, std::get<1>(m_data.top()));
        auto min = std::empty(m_data) ? x : std::min(x, std::get<2>(m_data.top()));

        m_data.emplace(x, max, min);
    }

    auto top() const
    { 
        return std::get<0>(m_data.top());
    }
 
    void pop() 
    { 
        m_data.pop();
    }
 
    auto max() const
    { 
        return std::get<1>(m_data.top());
    }

    auto min() const
    { 
        return std::get<2>(m_data.top());
    }

private:

    std::stack < std::tuple < T, T, T> > m_data;
};

/////////////////////////////////////////////////////////////////////////////////////

template < typename T > class Stack_v2
{
public:

    void push(T x)
    {
        if (std::empty(m_data)) 
        {
            m_data.push(x);
            
            m_max = m_data.top();
            m_min = m_data.top();
        }
        else if (x > m_max) 
        {
            m_data.push(2 * x - m_max);
            
            m_max = x;
        }
        else if (x < m_min) 
        {
            m_data.push(2 * x - m_min);
            
            m_min = x;
        }
        else 
        {
            m_data.push(x);
        }
    }

    auto top() const
    {
        if (m_data.top() > m_max)
        {
            return m_max;
        }
        else if (m_data.top() < m_min)
        {
            return m_min;
        }
        else 
        {
            return m_data.top();
        }
    }

    void pop()
    {
        if (auto t = m_data.top(); t > m_max)
        {
            (m_max *= 2) -= t;
        }
        if (auto t = m_data.top(); t < m_min)
        {
            (m_min *= 2) -= t;
        }

        m_data.pop();
    }
 
    auto max() const
    { 
        return m_max;
    }
 
    auto min() const
    { 
        return m_min;
    }
 
private:

    std::stack < T > m_data;
    
    T m_max = T();
    T m_min = T();
};

/////////////////////////////////////////////////////////////////////////////////////

int main()
{
    {
        Stack_v1 < int > stack_v1;

        stack_v1.push(3); assert(stack_v1.top() == 3); assert(stack_v1.max() == 3); assert(stack_v1.min() == 3);

        stack_v1.push(5); assert(stack_v1.top() == 5); assert(stack_v1.max() == 5); assert(stack_v1.min() == 3);

        stack_v1.push(1); assert(stack_v1.top() == 1); assert(stack_v1.max() == 5); assert(stack_v1.min() == 1);

        stack_v1.pop ( ); assert(stack_v1.top() == 5); assert(stack_v1.max() == 5); assert(stack_v1.min() == 3);

        stack_v1.pop ( ); assert(stack_v1.top() == 3); assert(stack_v1.max() == 3); assert(stack_v1.min() == 3);

        stack_v1.pop ( );
    }    
   
//  -------------------------------------------------------------------------------

    {
        Stack_v2 < int > stack_v2;

        stack_v2.push(3); assert(stack_v2.top() == 3); assert(stack_v2.max() == 3); assert(stack_v2.min() == 3);

        stack_v2.push(5); assert(stack_v2.top() == 5); assert(stack_v2.max() == 5); assert(stack_v2.min() == 3);

        stack_v2.push(1); assert(stack_v2.top() == 1); assert(stack_v2.max() == 5); assert(stack_v2.min() == 1);

        stack_v2.pop ( ); assert(stack_v2.top() == 5); assert(stack_v2.max() == 5); assert(stack_v2.min() == 3);

        stack_v2.pop ( ); assert(stack_v2.top() == 3); assert(stack_v2.max() == 3); assert(stack_v2.min() == 3);

        stack_v2.pop ( );
    }
}