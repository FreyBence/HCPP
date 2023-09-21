#include <iostream>
#include <vector>

using IntIterator = std::vector<int>::iterator; // alias gyakorlatban fontos

void ToConsole(const std::vector<int>&); // azért ez így nem túl szép


struct Student
{
    Student() = default;

    Student(const std::string name, const int age)
        : name(name)
        , age(age)
    {}
    std::string name;
    int age;

};

std::vector<int> LoadFromConsole()
{
    std::cout << "Hány számot szeretne megadni?" << std::endl;
    int a;
    std::cin >> a;
    std::vector<int> v1{a};
    for (auto& item : v1)
    {
        std::cin >> item;
    }

    return v1;
}

int main()
{
    std::vector<int> v1; //dinamikus méretű tömb, legyakrabban használt adat szerkezet

    v1.resize(10, 0);

    v1.reserve(5); // gyakorlatban fontos

    v1.push_back(5);
    v1.push_back(8);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(10);

    std::cout << "Size: " << v1.size() << std::endl;

    for (int i = 0; i < v1.size(); ++i) {
        std::cout << i << ". elem: " << v1[i] << std::endl;
    }

    std::cout << "Capacity: " << v1.capacity() << std::endl;

    v1.shrink_to_fit(); // gyakorlatban fontos

    std::cout << "Capacity after shrint to fit: " << v1.capacity() << std::endl;

    v1.clear(); // shrink to fittel együtt érdemes használni

    for (int i = 0; i < v1.size(); ++i) {
        std::cout << i << ". elem: " << v1[i] << std::endl;
    }

    std::cout << "Size after clear: " << v1.size() << std::endl;
    std::cout << "Capacity after clear: " << v1.capacity() << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////

    auto a{ 5 }; // auto - lényegében var, ahol csak lehet használjuk

    std::vector<int> v2{2, 3, 5, 7, 11};

    v2.push_back(5);
    v2.push_back(8);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(1);
    v2.push_back(4);
    v2.push_back(10);

    for (std::vector<int>::iterator it = v2.begin(); it != v1.end(); ++it) { //ugyanolyan gyors mint a sima for csak megközelítésban más
        // std::cout << *it << std::endl;

        std::cout << std::distance(v2.begin(), it) << ": " << *it << std::endl;
    }
    // const_iterator: rajta keresztül nem lehet módosítani csak lekérdezni (readonly)

    // cbegin és cend constans gegin és end - readonly, kötelező mellé aa const_iterator

    // v2.begin() helyett lehet std::begin(v2) - nem szokás

    for (auto& item : v1) {
        item = 42;
    }

    for (const auto& item : v1) {  // range based loop
        std::cout << item << std::endl;
    }

    ToConsole(v2);

    ////////////////////////////////////////////////////////////////////////////////////////////////


    Student s1{ "Hallgato Hanna", 19 };
    Student s2;
    s2.name = "Hallgato huba";
    s2.age = 42;

    std::vector<Student> students;
    students.push_back(s1);
    students.push_back(s2);

    students.push_back(Student{ "Valaki", 42 });
    students.emplace_back("Valaki2", 13);

    Student& newStudent = students.emplace_back();
}


void ToConsole(const std::vector<int>& v)
{
    auto separator = "";
    for (const auto& item : v)
    {
        std::cout << separator << item;
        separator = ", ";
    }
}
