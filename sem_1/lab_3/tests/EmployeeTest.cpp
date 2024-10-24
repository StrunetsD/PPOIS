#include <gtest/gtest.h>
#include "../src/Employee.h"
#include <string>

using namespace std;


TEST(EmployeeTest, CreateEmployee) {
    Employee emp("John Doe", 30, 5000.0);

    EXPECT_EQ(emp.getName(), "John Doe");
    EXPECT_EQ(emp.getAge(), 30);
    EXPECT_DOUBLE_EQ(emp.getSalary(), 5000.0);
}


TEST(EmployeeTest, GetSalary) {
    Employee emp("Alice", 25, 6000.0);
    EXPECT_DOUBLE_EQ(emp.getSalary(), 6000.0);
}


TEST(EmployeeTest, SetSalary) {
    Employee emp("Bob", 40, 7000.0);
    emp.setSalary(8000.0);
    EXPECT_DOUBLE_EQ(emp.getSalary(), 8000.0);
}


TEST(EmployeeTest, WorkTest) {
    Employee emp("Jane", 35, 9000.0);
    emp.work();
}
