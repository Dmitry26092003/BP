#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string m_name;
    float m_height;
    float m_weight;
    string m_result_BMI;
    float m_BMI;


    void calculate();

    Person(string name, float height, float weight) : m_name(name), m_height(height), m_weight(weight)
    {
    };

    friend std::ostream& operator<< (std::ostream &out, const Person &pers)
    {
        out << "Name: " << pers.m_name << endl
            << "Height(sm): " << pers.m_height*100 << endl
            << "Weight(Kg): " << pers.m_weight << endl
            << pers.m_result_BMI << endl
            << "BMI: " << pers.m_BMI << endl << endl;

        return out;
    }

};


void Person::calculate()
{
    m_BMI = m_weight / (m_height*m_height);
    if (m_BMI < 18.49)
    {
        m_result_BMI = "low";
    }
    else if (m_BMI < 24.99)
    {
        m_result_BMI = "normal";
    }
    else
    {
        m_result_BMI = "high";
    }

}

int main()
{
    Person Cursed("Cursed", 1.8, 55);
    Cursed.calculate();
    cout << Cursed;

    Person vitaliy("Vitaly", 1.7, 95);
    vitaliy.calculate();
    cout << vitaliy;

    Person Vasily("Vasily", 2, 80);
    Vasily.calculate();
    cout << Vasily;
    return 0;
}
