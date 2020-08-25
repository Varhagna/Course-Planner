#include "CourseComponent.hpp"
#include "CatalogReader.hpp"
#include "Prerequisite.hpp"
#include "Course.hpp"
#include "major/AbstractMajor.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    // Student passes in major
    string major;

    cout << "Enter a major: ";
    cin >> major;
    cout << endl;

    // Convert user string to uppercase for simplicity purposes
    for_each(major.begin(), major.end(), [](char & c) {
        c = ::toupper(c);
    }

    AbstractMajor* userMajor;
    // Major gets passed into Catalog Reader
    if (major == "BIOENGINEERING" || major == "BIEN" ) {
        userMajor = new Bioengineering();
    }

    else if (major == "CHEMICAL ENGINEERING" || major == "CHEME") {
        userMajor = new ChemicalEngineering();
    }

    else if (major == "COMPUTER ENGINEERING" || major == "CHEME") {
        userMajor = new ComputerEngineering();
    }

    else if (major == "COMPUTER SCINECE" || major == "COMP SCI") {
        userMajor = new ComputerScience();
    }

    else if (major == "COMPUTER SCIENCE WITH BUSINESS APPLICATIONS" || major == "CSBA") {
        userMajor = new CSBusinessApplications();
    }

    else if (major == "ELECTRICAL ENGINEERING" || major == "EE") {
        userMajor = new ElectricalEngineering();
    }

    else if (major == "ENVIRONMENTAL ENGINEERING" || major == "ENVE") {
        userMajor= new EnvironmentalEngineering();
    }
    
    else if (major == "MECHANICAL ENGINEERING" || major == "ME") {
        userMajor = new MechanicalEngineering();
    }

    else if (major == "MATERIALS SCIENCE AND ENGINEERING" || major == "MSE" || major == "MATERIAL SCIENCE AND ENGINEERING") {
        userMajor = new MaterialScience();
    }

    // Program exits if the user inputs an invalid major
    else {
        cout << "Invalid major entered." << endl;
        exit(1);
    }

    
    CatalogReader reader(userMajor);
    
    // Returns unordered map of courses, stored by "name of course", <vector of linked courses and itself>
    unordered_map<string, list<CourseComponent*>>* majorCourses = reader.createCourseHeirarchy();

    













    








}
