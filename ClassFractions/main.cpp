#include<iostream>
#include<string>
int gcd(int a, int b)
{
    while(b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
////////////////////////////////////////////////
class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(): numerator(1), denominator(1){}
    Fraction(int _n, int _d)
    {
        set_numenator(_n);
        set_denominator(_d);
    }
    ~Fraction()
    {

    }

    void set_numenator(int _n)
    {
        numerator = _n;
    }
    void set_denominator(int _d)
    {
        if(_d == 0)
        {
            std::cout << "Error. Denominator cannot be zero!" << std::endl;
            std::exit(0);
        }
        else
        {
            denominator = _d;
        }
    }

    int get_numenator()
    {
        return numerator;
    }
    int get_denominator()
    {
        return denominator;
    }

    Fraction operator + (Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator+otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }

    Fraction operator - (Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator-otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }

    Fraction operator * (Fraction otherFraction)
    {
        int n = numerator*otherFraction.numerator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }

    Fraction operator / (Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator;
        int d = denominator*otherFraction.numerator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }

    Fraction operator +=(Fraction otherFraction)
    {
        return *this = *this + otherFraction;
    }

    Fraction operator -=(Fraction otherFraction)
    {
        return *this = *this - otherFraction;
    }

    Fraction operator *=(Fraction otherFraction)
    {
        return *this = *this * otherFraction;
    }

    Fraction operator /=(Fraction otherFraction)
    {
        return *this = *this / otherFraction;
    }

    bool operator ==(Fraction otherFraction)
    {
        return (numerator * otherFraction.denominator == denominator * otherFraction.numerator);
    }

    bool operator !=(Fraction otherFraction)
    {
        return (numerator * otherFraction.denominator != denominator * otherFraction.numerator);
    }

    bool operator <(Fraction otherFraction)
    {
        return (numerator * otherFraction.denominator < denominator * otherFraction.numerator);
    }

    bool operator >(Fraction otherFraction)
    {
        return (numerator * otherFraction.denominator > denominator * otherFraction.numerator);
    }

    bool operator <=(Fraction otherFraction)
    {
        return (numerator * otherFraction.denominator <= denominator * otherFraction.numerator);
    }

    bool operator >=(Fraction otherFraction)
    {
        return (numerator * otherFraction.denominator >= denominator * otherFraction.numerator);
    }

    void print_fraction()
    {
        std::cout << numerator << "/" << denominator ;
    }
};

int main()
{
    Fraction f1(3, 5);
    Fraction f2(2, 7);
    std::cout << std::endl;
    std::cout << "Operator overloading ( +, -, *, / )" << std::endl;
    std::cout << std::endl;
    Fraction res = f1 + f2;
    f1.print_fraction();
    std::cout << " + ";
    f2.print_fraction();
    std::cout << " = ";
    res.print_fraction();
    std::cout << std::endl;


    res = f1 - f2;
    f1.print_fraction();
    std::cout << " - ";
    f2.print_fraction();
    std::cout << " = ";
    res.print_fraction();
    std::cout << std::endl;

    res = f1 * f2;
    f1.print_fraction();
    std::cout << " * ";
    f2.print_fraction();
    std::cout << " = ";
    res.print_fraction();
    std::cout << std::endl;

    res = f1 / f2;
    f1.print_fraction();
    std::cout << " / ";
    f2.print_fraction();
    std::cout << " = ";
    res.print_fraction();
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Operator overloading ( +=, -=, *=, /=, ==, !=, <, >, <=, >= )" << std::endl;
    std::cout << std::endl;
    res.print_fraction();
    std::cout << " += ";
    f1.print_fraction();
    std::cout << " = ";
    res += f1;
    res.print_fraction();
    std::cout << std::endl;

    res.print_fraction();
    std::cout << " -= ";
    f1.print_fraction();
    std::cout << " = ";
    res -= f1;
    res.print_fraction();
    std::cout << std::endl;

    res.print_fraction();
    std::cout << " *= ";
    f1.print_fraction();
    std::cout << " = ";
    res *= f1;
    res.print_fraction();
    std::cout << std::endl;

    res.print_fraction();
    std::cout << " /= ";
    f1.print_fraction();
    std::cout << " = ";
    res /= f1;
    res.print_fraction();
    std::cout << std::endl;
    std::cout << std::endl;

    f1.print_fraction();
    std::cout << " == ";
    f2.print_fraction();
    std::cout << " ? : " << (f1 == f2) << std::endl;

    f1.print_fraction();
    std::cout << " != ";
    f2.print_fraction();
    std::cout << " ? : " << (f1 != f2) << std::endl;

    f1.print_fraction();
    std::cout << " < ";
    f2.print_fraction();
    std::cout << " ? : " << (f1 < f2) << std::endl;

    f1.print_fraction();
    std::cout << " > ";
    f2.print_fraction();
    std::cout << " ? : " << (f1 > f2) << std::endl;

    f1.print_fraction();
    std::cout << " <= ";
    f2.print_fraction();
    std::cout << " ? : " << (f1 <= f2) << std::endl;

    f1.print_fraction();
    std::cout << " >= ";
    f2.print_fraction();
    std::cout << " ? : " << (f1 >= f2) << std::endl;

    return 0;
}
