#include <string>
#include <iostream>

/*
Сформулируйте способы ослабления монолитности и перегруженности класса для строк std::basic_string
Используем паттерн Visitor: выносим реализацию нового функционала в Visitor-a
*/

class Visitor
{
public :

    virtual ~Visitor() = default;

//  ----------------------------------------------------------

    virtual void visit(const class UpgradedString * client) const = 0;
    
};

class BasicString
{
public :

    virtual ~BasicString() = default;

//  ---------------------------------------------------------

    virtual void test() const = 0;

    virtual void visit_by(const Visitor & visitor) const = 0;
};

///////////////////////////////////////////////////////////////////////

class UpgradedString : public BasicString 
{
public :

    void visit_by(const Visitor & visitor) const override
    { 
        visitor.visit(this);
    }
};