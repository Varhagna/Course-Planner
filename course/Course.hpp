#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include "CourseComponent.hpp"

#include <string>
#include <vector>
#include <iostream>

class Course : public CourseComponent {

    private:    
        vector<CourseComponent*> prerequisites;
        vector<string> courseRequisites;

    public:
        // Defualt Constructor
        Course() : CourseComponent() {
            courseName = "CRS 001";
            courseDescription = "A default course";
            courseUnits = 4;
            courseRequisites = "PREQ 001";
        }

        // Constructor
        Course(string newCourseName, int numUnits, string newCourseDescription, string newCourseRequisites) : CourseComponent() {
            courseName = newCourseName;
            courseUnits = numUnits;
            courseDescription = newCourseDescription;
            courseRequisites = newCourseRequisites;
        }

        // Accessor that returns Course Requisites
        string getCourseRequisites() {
            return courseRequisites;
        }

        // Adds other courses to the list 
        void add(CourseComponent *newCourseComponent) {
            prerequisites.push_back(newCourseComponent);
        }

        // Removes courses from the list
        void remove(CourseComponent *newCourseComponent) {
            unsigned int i;
            for (i = 0; i < prerequisites.size(); ++i) {
                if (prerequisites[i] == newCourseComponent) {
                    // TODO
                    // Revisit this to remove everything from a course subtree
                }
            }
        }

        // Returns the course stored at a specific index
        CourseComponent* getComponent(int componentIndex) {
            return prerequisites.at(componentIndex);
        }

        // Check this function
        void displayCourseInfo() { 
            cout << "Course Name: " << getCourseName() << endl;
            cout << "Number of Units: " << getCourseUnits() << endl;
            cout << "Course Description: " << getCourseDescription() << endl;
        }





};

#endif // __COURSE_HPP__