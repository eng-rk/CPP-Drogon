#include <drogon/drogon.h>
#include "StudentManager.h"

using namespace drogon;

StudentManager manager;

void addCorsHeaders(const HttpResponsePtr& resp)
{
    resp->addHeader("Access-Control-Allow-Origin", "http://localhost:5173");
    resp->addHeader("Access-Control-Allow-Headers", "Content-Type");
    resp->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
}

int main()
{
    // OPTIONS /students
    app().registerHandler(
        "/students",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback)
        {
            auto resp = HttpResponse::newHttpResponse();
            addCorsHeaders(resp);
            callback(resp);
        },
        {Options});

    // GET /students
    app().registerHandler(
        "/students",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback)
        {
            Json::Value result(Json::arrayValue);

            for (const auto& student : manager.getStudents())
            {
                Json::Value s;
                s["id"] = student.getId();
                s["name"] = student.getName();

                Json::Value courses(Json::arrayValue);

                for (const auto& course : student.getCourses())
                {
                    Json::Value c;
                    c["courseName"] = course.courseName;
                    c["grade"] = course.grade;
                    courses.append(c);
                }

                s["courses"] = courses;
                result.append(s);
            }

            auto resp = HttpResponse::newHttpJsonResponse(result);
            addCorsHeaders(resp);
            callback(resp);
        },
        {Get});

    // POST /students
    app().registerHandler(
        "/students",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback)
        {
            auto json = req->getJsonObject();
            Json::Value result;

            if (!json || !(*json).isMember("name"))
            {
                result["success"] = false;
                result["message"] = "Name is required";

                auto resp = HttpResponse::newHttpJsonResponse(result);
                resp->setStatusCode(k400BadRequest);
                addCorsHeaders(resp);
                callback(resp);
                return;
            }

            std::string name = (*json)["name"].asString();
            manager.addStudent(name);

            result["success"] = true;
            result["message"] = "Student added successfully";

            auto resp = HttpResponse::newHttpJsonResponse(result);
            addCorsHeaders(resp);
            callback(resp);
        },
        {Post});

    // OPTIONS /students/{id}/courses
    app().registerHandler(
        "/students/{1}/courses",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback,
           int studentId)
        {
            auto resp = HttpResponse::newHttpResponse();
            addCorsHeaders(resp);
            callback(resp);
        },
        {Options});

    // POST /students/{id}/courses
    app().registerHandler(
        "/students/{1}/courses",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback,
           int studentId)
        {
            auto json = req->getJsonObject();
            Json::Value result;

            if (!json || !(*json).isMember("courseName") || !(*json).isMember("grade"))
            {
                result["success"] = false;
                result["message"] = "courseName and grade are required";

                auto resp = HttpResponse::newHttpJsonResponse(result);
                resp->setStatusCode(k400BadRequest);
                addCorsHeaders(resp);
                callback(resp);
                return;
            }

            std::string courseName = (*json)["courseName"].asString();
            float grade = (*json)["grade"].asFloat();

            bool added = manager.addCourseToStudent(studentId, courseName, grade);

            if (!added)
            {
                result["success"] = false;
                result["message"] = "Student not found";

                auto resp = HttpResponse::newHttpJsonResponse(result);
                resp->setStatusCode(k404NotFound);
                addCorsHeaders(resp);
                callback(resp);
                return;
            }

            result["success"] = true;
            result["message"] = "Course added successfully";

            auto resp = HttpResponse::newHttpJsonResponse(result);
            addCorsHeaders(resp);
            callback(resp);
        },
        {Post});

    app().addListener("127.0.0.1", 8080);
    app().run();

    return 0;
}