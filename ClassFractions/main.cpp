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
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main()
{
    std::cout << "Start project" << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
