#include <iostream>
#include <string>
using namespace std;

struct IOutput
{
    virtual void Show() = 0;
    virtual void Show(string info) = 0;
};
struct IMath
{
    virtual int Max() = 0;
    virtual int Min() = 0;
    virtual float Avg() = 0;
    virtual bool Search(int valueToSearch) = 0;
};
struct ISort
{
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
};

class Array : public IOutput, public IMath, public ISort
{
    int* arr = nullptr;
    int size = 0;
public:
    Array() = default;
    Array(int s) : size(s) 
    {
        arr = new int[size];
        srand(time(0));
        for (size_t i = 0; i < size; i++) { arr[i] = rand() % 10; }
    }
    int GetSize() const { return size; }

    void Show()
    {
        for (size_t i = 0; i < size; i++) { cout << arr[i] << " | "; }
        cout << endl;
    }
    void Show(string info) 
    {
        cout << info << endl;
        Show();
    }

    int Max()
    {
        int t = arr[0];
        for (size_t i = 0; i < size; i++) { if (arr[i] > t) { t = arr[i]; } }
        return t;
    }
    int Min()
    {
        int t = arr[0];
            for (size_t i = 0; i < size; i++) { if (arr[i] < t) { t = arr[i]; } }
        return t;
    }
    float Avg()
    {
        float s = 0;
        for (size_t i = 0; i < size; i++) { s += arr[i]; }
        return s / size;
    }
    bool Search(int valueToSearch)
    {
        for (size_t i = 0; i < size; i++) { if (arr[i] == valueToSearch) { return true; } }
        return false;
    }

    void SortAsc()
    {
        int t;
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }
    }
    void SortDesc() 
    {
        int t;
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }
    }
    void SortByParam(bool isAsc)
    {
        if (isAsc) { SortAsc(); }
        else { SortDesc(); }
    }

    ~Array()
    {
        delete[] arr;
    }
};


struct IShape
{
    virtual void CalculateArea() = 0;
    virtual void CalculatePerimeter() = 0;
};
class Rectangle : public IShape
{
    int a = 0;
    int b = 0;
public:
    Rectangle(int _a, int _b) : a(_a), b(_b) {}
    void CalculateArea()
    {
        cout << "Area of rectangle = " << a * b << endl;
    }
    void CalculatePerimeter()
    {
        cout << "Perimeter of rectanlge = " << (a + b) * 2 << endl;
    }
};
class Circle : public IShape
{
    int r = 0;
public:
    Circle(int _r) : r(_r) {}
    void CalculateArea()
    {
        cout << "Area of circle = " << 3.14 * r * r << endl;
    }
    void CalculatePerimeter()
    {
        cout << "Perimeter of circle = " << 2 * 3.14 * r << endl;
    }
};
class Triangle : public IShape
{
    int s = 0;
public:
    Triangle(int _s) : s(_s) {}
    void CalculateArea()
    {
        cout << "Area of triangle = " <<  (1.73/4) * s * s << endl;
    }
    void CalculatePerimeter()
    {
        cout << "Perimeter of triangle = " << s*3 << endl;
    }
};

struct IDrivable
{
    virtual void StartEngine() = 0;
    virtual void StopEngine() = 0;
    virtual void Drive() = 0;
};

class Car : public IDrivable
{
    bool isActive = false;
public:
    void StartEngine()
    {
        isActive = true;
        cout << "Car engine started\n";
    }
    void StopEngine()
    {
        isActive = false;
        cout << "Car engine stoped\n";
    }
    void Drive()
    {
        if (isActive) { cout << "Car is driving...\n"; }
        else { cout << "Engine is not active, car can't drive\n"; }
    }
};

class Motorcycle : public IDrivable
{
    bool isActive = false;
public:
    void StartEngine()
    {
        isActive = true;
        cout << "Motorcycle engine started\n";
    }
    void StopEngine()
    {
        isActive = false;
        cout << "Motorcycle engine stoped\n";
    }
    void Drive()
    {
        if (isActive) { cout << "Motorcycle is driving...\n"; }
        else { cout << "Engine is not active, motorcycle can't drive\n"; }
    }
};

int main()
{
    Array a(6);
    a.Show("Array: ");
    cout << "Max: " << a.Max() << endl;
    cout << "Min: " << a.Min() << endl;
    cout << "Avg:" << a.Avg() << endl;
    cout << "Is There 6? (1 - true, 0 - false): " << a.Search(6) << endl;
    cout << "Asc Sort:\n";
    a.SortByParam(true);
    a.Show();
    cout << "Desc Sort:\n";
    a.SortByParam(false);
    a.Show();

    cout << "\nFigures:\n";
    Rectangle* rect = new Rectangle(3, 4);
    Circle* cir = new Circle(5);
    Triangle* tri = new Triangle(6);

    IShape* figures[3];
    figures[0] = rect;
    figures[1] = cir;
    figures[2] = tri;

    for (size_t i = 0; i < 3; i++)
    {
        figures[i]->CalculateArea();
        figures[i]->CalculatePerimeter();
    }

    cout << "\nTransport:\n";
    Car* car = new Car();
    Motorcycle* motorcycle = new Motorcycle();

    IDrivable* transport[2];
    transport[0] = car;
    transport[1] = motorcycle;
    for (size_t i = 0; i < 2; i++)
    {
        transport[i]->Drive();
        transport[i]->StartEngine();
        transport[i]->Drive();
        transport[i]->StopEngine();
        cout << endl;
    }
}