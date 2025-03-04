#include <iostream>

class Complex
{
private:
    double real, img;


public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c)
    {
        real = c.real;
        img = c.img;
    }

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);
    Complex& operator=(const Complex& c);

    void println()
    {
        std::cout << "( " << real << ", " << img << " ) " << std::endl;
    }
};

Complex Complex::operator+(const Complex& c) const
{
    Complex temp(real+c.real, img+c.img);

    return temp;
}

Complex Complex::operator-(const Complex& c) const
{
    Complex temp(real - c.real, img - c.img);

    return temp;
}

Complex Complex::operator*(const Complex& c) const
{
    // (a+bi)(c+di) = ac + adi + bci + pow(bdi,2) = i제곱을 -1이라고 적용
    // 허수는 허수끼리 실수는 실수끼리 더함 => (ac - bd, i(ad, bc))
    Complex temp( real * c.real - img * c.img, real * c.img + img * c.real);

    return temp;
}


Complex Complex::operator/(const Complex &c) const
{
    Complex temp(0,0);

    double reals = ((real * c.real) + (img * c.img)) / ((c.real * c.real) + (c.img * c.img));
    double imgs = ((img * c.real) - (real * c.img)) / ((c.real * c.real) + (c.img * c.img));

    temp = Complex(reals, imgs);

    return temp;
}


Complex& Complex::operator+=(const Complex &c)
{
    (*this) = (*this) + c;

    return *this;
}

Complex& Complex::operator-=(const Complex &c)
{
    (*this) = (*this) - c;

    return *this;
}

Complex& Complex::operator*=(const Complex &c)
{
    (*this) = (*this) * c;

    return *this;
}

Complex& Complex::operator/=(const Complex &c)
{
    (*this) = (*this) / c;

    return *this;
}

Complex& Complex::operator=(const Complex &c)
{
    this->real = c.real;
    this->img = c.img;

    return  *this;
}


int main()
{
    Complex cp1(1.0, 2.0);
    Complex cp2(3.0, -2.0);

    Complex cp3 = cp1 * cp2;

    cp3.println();

    cp3 += cp1;

    cp3.println();
}



