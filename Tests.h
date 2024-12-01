#pragma once
#include <cassert>

#include "./utils.h"
#include "db/Database.h"
#include "services/CourseService.h"
#include "services/EnrollService.h"
#include "services/LoginService.h"

namespace icpproject {
    inline void LoginServiceTest() {
        auto runServiceTest = [](auto service, auto signupData, String ^ testName) {
            try {
                // Signup Test
                infoMsg("Signing up " + testName, testName + "SignUp");
                auto signupRes = service->SignUp(signupData);
                assert(signupRes.status, testName + " signup failed");

                // Login Test
                auto loginUser = LoginUser{signupData.email, signupData.password};
                infoMsg("Logging in " + testName, testName + "Login");
                auto loginRes = service->Login(loginUser);
                assert(loginRes.status, testName + " login failed");

                // Detailed Login Verification
                debugMsg(String::Format("User: {0} {1} logged in", loginRes.data->FirstName, loginRes.data->LastName),
                         testName + "Login");
            } catch (Exception ^ e) {
                errorMsg(e->Message, testName + "Test");
                throw;
            }
        };

        // Admin Service Test
        runServiceTest(gcnew AdminService(), SignupUser{"Madiba", "Hudson-Quansah", "madmin@gmail.com", "madiba123"},
                       "Admin");

        // Student Service Test
        runServiceTest(gcnew StudentService(),
                       SignupStudent{"Madiba", "Hudson-Quansah", "mstu@gmail.com", "madiba123", "2004-01-18",
                                     "C:\\Users\\HP\\Pictures\\photo_2020-06-07_10-39-46.jpg", Major::CS, "2022-01-01"},
                       "Student");

        // Faculty Service Test
        runServiceTest(
            gcnew FacultyService(),
            SignupFaculty{"Madiba", "Hudson-Quansah", "mfac@gmail.com", "madiba123", "2020-12-01", Department::CS},
            "Faculty");

        infoMsg("All Service Tests Passed", "Tests");
    }

    inline void CourseServiceTest() {
        AdminService ^ adminService = gcnew AdminService();
        auto res = adminService->Login(LoginUser{"madmin@gmail.com", "madiba123"});
        assert(res.status, "Admin login failed");
        CourseService ^ courseService = gcnew CourseService(res.data);

        PreReqList ^ prereqCourses = gcnew PreReqList(1);
        long long addedCourseId = 0;

        auto addPrerequisiteCourses = [&](CourseService ^ courseService, PreReqList ^ prereqCourses) {
            cli::array<NewCourse> ^ courses = {NewCourse("Intro to Programming", 1, Semester::S1, 40),
                                               NewCourse("Data Structures", 1, Semester::S2, 35),
                                               NewCourse("Algorithms", 1, Semester::S1, 30)};

            for (int i = 0; i < courses->Length; i++) {
                auto addResult = courseService->Add(courses[i]);
                assert(addResult.status, "Prerequisite course addition failed");
                prereqCourses->Add(i + 1);
            }
            debugMsg("Prerequisite courses added", "CourseServiceTest");
        };

        auto addCourse = [&](CourseService ^ courseService, PreReqList ^ prereqCourses) {
            NewCourse newCourse("Advanced Programming", 3.0, Semester::S1, 30, prereqCourses);
            auto addResult = courseService->Add(newCourse);
            assert(addResult.status, "Course addition failed");
            addedCourseId = courseService->GetAll().data->Rows->Count;
            debugMsg("Advanced course added with prerequisites", "CourseServiceTest");
        };

        auto updateCourse = [&](CourseService ^ courseService, PreReqList ^ prereqCourses) {
            Course existingCourse(addedCourseId, "Updated Advanced Programming", 4.0, Semester::S2, 35, prereqCourses);
            auto updateResult = courseService->Update(existingCourse);
            assert(updateResult.status, "Course update failed");
            debugMsg("Course updated successfully", "CourseServiceTest");
        };

        auto getByIdCourse = [&](CourseService ^ courseService) {
            auto courseResult = courseService->GetById(addedCourseId);
            assert(courseResult.status, "Get course by ID failed");
            debugMsg("Retrieved course by ID successfully", "CourseServiceTest");
        };

        auto getAllCourses = [&](CourseService ^ courseService) {
            auto coursesResult = courseService->GetAll();
            assert(coursesResult.status, "Get all courses failed");
            assert(coursesResult.data->Rows->Count > 0, "No courses found");
            debugMsg("Retrieved all courses successfully", "CourseServiceTest");
        };

        auto getRemainingCapacity = [&](CourseService ^ courseService) {
            auto capacityResult = courseService->GetRemainingCapacity(addedCourseId);
            assert(capacityResult.status, "Get remaining capacity failed");
            assert(capacityResult.data == 35, "Incorrect remaining capacity");
            debugMsg("Retrieved remaining capacity successfully", "CourseServiceTest");
        };

        auto getPrereqCourses = [&](CourseService ^ courseService) {
            auto prereqResult = courseService->GetPrereqCourses(addedCourseId);
            assert(prereqResult.status, "Get prerequisite courses failed");
            assert(prereqResult.data->Count > 0, "No prerequisite courses found");
            debugMsg("Retrieved prerequisite courses successfully", "CourseServiceTest");
        };

        auto deleteCourse = [&](CourseService ^ courseService) {
            auto deleteResult = courseService->Delete(addedCourseId);
            assert(deleteResult.status, "Course deletion failed");
            debugMsg("Course deleted successfully", "CourseServiceTest");
        };

        try {
            addPrerequisiteCourses(courseService, prereqCourses);
            addCourse(courseService, prereqCourses);
            updateCourse(courseService, prereqCourses);
            getByIdCourse(courseService);
            getAllCourses(courseService);
            getRemainingCapacity(courseService);
            getPrereqCourses(courseService);
            deleteCourse(courseService);

            infoMsg("All CourseService Tests Passed", "CourseServiceTest");
        } catch (Exception ^ e) {
            errorMsg("CourseService Test failed: " + e->Message, "CourseServiceTest");
            throw;
        }
    }

    inline void EnrollServiceTest() {
        StudentService ^ studentService = gcnew StudentService();
        auto res = studentService->Login(LoginUser{"mstu@gmail.com", "madiba123"});
        assert(res.status, "Student login failed");
        EnrollService ^ service = gcnew EnrollService(res.data);

        auto enrollInCourse = [&](EnrollService ^ s, long long uid) {
            auto res = s->Enroll(NewEnrollment{uid, 1, Semester::S1, Grade::NG});
            assert(res.status, "Enrollment failed");
            debugMsg("Enrolled in course successfully", "EnrollServiceTest");
        };

        try {
            enrollInCourse(service, res.data->UID);

            infoMsg("All EnrollService Tests Passed", "EnrollServiceTest");
        } catch (Exception ^ e) {
            errorMsg("EnrollService Test failed: " + e->Message, "EnrollServiceTest");
            throw;
        }
    }
}  // namespace icpproject