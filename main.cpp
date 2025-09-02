// Axmad Xurshetov 220122
// Monday 14:00

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <future>
#include <stdexcept>

// -------------------- Main Function --------------------
// Q1: Write a program that prints the number of command-line arguments it receives and lists them.
int main_func_example(int argc, char* argv[]) {
    std::cout << "Number of arguments received: " << argc << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}

// Q2
// Answer: The primary purpose of the main function is to serve as the entry point of the program. 
// In Java, it is declared as 'static' because it must be callable without creating an instance of the class.

// Q3
// Answer: C++: int main(int argc, char* argv[])
// Java: public static void main(String[] args)
// Differences: return type (int vs void), parameters (char* vs String[]), and access modifiers (Java uses public static).

// Q4
// Answer: In C++, the return value of main indicates the exit status (0 = success, non-zero = error).
// In Java, System.exit(code) is used to return a non-zero exit status.

// -------------------- Variables --------------------
// Q1: Swap without temporary variable
void variable_example() {
    int a = 10, b = 20;
    std::cout << "Before swap: a=" << a << " b=" << b << std::endl;
    a = a + b;
    b = a - b;
    a = a - b;
    std::cout << "After swap: a=" << a << " b=" << b << std::endl;
}

// Q2
// Answer: Primitive types (int, double) store values directly in memory. 
// Reference types (objects, pointers) store addresses to the actual data.
// Q3
// Answer: Scope defines where a variable can be accessed. 
// Local scope = inside a function, class/static scope = shared by all instances.
// Q4
// Answer: Statically-typed means variable types are checked at compile-time. 
// Dynamically-typed means types are resolved at runtime (e.g., Python).

// -------------------- Control Flow --------------------
void control_flow_example() {
    int n1 = 0, n2 = 1, nextTerm;
    std::cout << "Fibonacci: ";
    for (int i = 1; i <= 10; i++) {
        if (i == 1) { std::cout << n1 << " "; continue; }
        if (i == 2) { std::cout << n2 << " "; continue; }
        nextTerm = n1 + n2;
        n1 = n2; n2 = nextTerm;
        std::cout << nextTerm << " ";
    }
    std::cout << std::endl;
}
// Q2: while checks before execution, do-while executes at least once.
// Q3: Switch allows branching with cases; break prevents fall-through; default is fallback.
// Q4: Short-circuit evaluation stops as soon as the result is known (useful for avoiding null pointer errors).

// -------------------- Functions / Methods --------------------
bool isPalindrome(const std::string& str) {
    return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}
// Q2: C++ supports pass-by-value, pass-by-pointer, and pass-by-reference. Java only passes by value (object refs by value).
// Q3: Overloading = same function name with different parameter lists. 
// Q4: Recursion = function calling itself. Base case prevents infinite recursion.

// -------------------- Comments --------------------
// Single-line: // comment
// Multi-line:
/*
 This is a multi-line comment.
*/
// Documentation:
/**
 * This function demonstrates documentation comment.
 */
// Q2: Comments improve maintainability in teams.
// Q3: Javadoc/Doxygen generate structured docs.
// Q4: Good code should be self-explanatory, but comments help for complex logic.

// -------------------- Classes --------------------
class BankAccount {
private:
    double balance;
public:
    BankAccount(double initial) { balance = initial >= 0 ? initial : 0; }
    void deposit(double amount) { if (amount > 0) balance += amount; }
    double getBalance() { return balance; }
};
// Q2: Class = blueprint; Object = instance of class.
// Q3: public = accessible anywhere, private = only in class, protected = in class & subclasses.
// Q4: Constructor initializes object. Default constructor is auto-generated if none provided.

// -------------------- Enums --------------------
enum class Season { SPRING, SUMMER, AUTUMN, WINTER };
std::string recommendActivity(Season s) {
    switch (s) {
        case Season::SPRING: return "Plant flowers";
        case Season::SUMMER: return "Go to the beach";
        case Season::AUTUMN: return "Rake leaves";
        case Season::WINTER: return "Build a snowman";
        default: return "Rest";
    }
}
// Q2: Enums improve readability and prevent invalid values.
// Q3: Enums increase type safety and self-documentation.
// Q4: Java enums can have methods/fields; C++ scoped enums are safer than old C-style enums.

// -------------------- Inheritance --------------------
class Vehicle {
public: void startEngine() { std::cout << "Engine started.\n"; } };
class Car : public Vehicle {
public: void drive() { std::cout << "Car is driving.\n"; } };
// Q2: Inheritance = "is-a"; Composition = "has-a".
// Q3: Overriding = redefining base method. C++ uses virtual/override, Java uses @Override.
// Q4: Diamond problem = ambiguity in multiple inheritance. C++ fixes with virtual inheritance, Java avoids by interfaces.

// -------------------- Mixins / Interfaces --------------------
class IStringable {
public:
    virtual std::string toString() const = 0;
    virtual ~IStringable() = default;
};
class Printable {
public:
    void print(const IStringable& obj) { std::cout << obj.toString() << std::endl; }
};
class Book : public IStringable {
    std::string title, author;
public:
    Book(std::string t, std::string a): title(t), author(a) {}
    std::string toString() const override { return "'" + title + "' by " + author; }
};
// Q2: Mixins/interfaces allow code reuse without strict hierarchy.
// Q3: Java interfaces with default methods work like mixins.
// Q4: Tradeoffs: inheritance = rigid, composition = flexible, mixins = reusable features.

// -------------------- Polymorphism --------------------
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};
class Rectangle : public Shape {
    double w,h;
public: Rectangle(double a,double b):w(a),h(b){} double getArea() const override {return w*h;} };
class Circle : public Shape {
    double r;
public: Circle(double rr):r(rr){} double getArea() const override {return 3.14159*r*r;} };
// Q2: Compile-time = overloading, templates. Runtime = overriding, virtual functions.
// Q3: Abstract class = cannot be instantiated. Interface = pure abstract contract.
// Q4: Both abstract classes and interfaces enable polymorphism.

// -------------------- Async Operations --------------------
long long calculateSum() {
    long long sum = 0;
    for (long long i=1;i<=1000000;i++) sum+=i;
    return sum;
}
void async_example() {
    std::future<long long> result = std::async(std::launch::async, calculateSum);
    std::cout << "Calculating...\n";
    std::cout << "Result = " << result.get() << std::endl;
}
// Q2: Async programming prevents blocking in I/O operations.
// Q3: Parallel = tasks at the same time, Concurrent = tasks appear simultaneous but share resources.
// Q4: Future/Promise store results of async tasks until ready.

// -------------------- Exceptions --------------------
void processAge(int age) {
    if (age < 0) throw std::invalid_argument("Age cannot be negative.");
    std::cout << "Age = " << age << std::endl;
}
void exception_example() {
    try {
        processAge(-5);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
// Q2: try = risky code, catch = handle error, finally = cleanup. C++ uses RAII for cleanup.
// Q3: Java has checked/unchecked exceptions; C++ doesn’t distinguish.
// Q4: Exceptions separate normal flow from error handling, but may be costly if overused.

// -------------------- MAIN --------------------
int main(int argc, char* argv[]) {
    variable_example();
    control_flow_example();
    std::cout << (isPalindrome("madam") ? "Palindrome\n" : "Not palindrome\n");

    BankAccount acc(100); acc.deposit(50);
    std::cout << "Balance: " << acc.getBalance() << std::endl;

    std::cout << recommendActivity(Season::SUMMER) << std::endl;

    Car car; car.startEngine(); car.drive();

    Book b("The Hobbit","Tolkien"); Printable p; p.print(b);

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(10,5));
    shapes.push_back(std::make_unique<Circle>(3));
    for (auto& s : shapes) std::cout << "Area: " << s->getArea() << std::endl;

    async_example();
    exception_example();

    return 0;
}

