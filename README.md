
# 🎓 Student Course Management System (C++ Drogon + React)

A full-stack web application built using **C++ (Drogon Framework)** for the backend and **React (Vite)** for the frontend.

This project demonstrates building a high-performance backend in C++ and connecting it with a modern frontend.

---

## 🚀 Features

- ➕ Add new students
- 📋 View all students
- 📚 Add courses with grades
- 🔄 Real-time UI updates
- 🌐 REST API using Drogon
- ⚡ Fast frontend with React + Vite

---

## 🛠️ Tech Stack

### 🔹 Backend
- C++
- Drogon Framework
- JsonCpp
- vcpkg

### 🔹 Frontend
- React (Vite)
- JavaScript
- CSS

---

## 📂 Project Structure

```

FinalProjectC++react/
│
├── backend/
│   ├── main.cpp
│   ├── Student.h
│   ├── Student.cpp
│   ├── StudentManager.h
│   └── StudentManager.cpp
│
├── frontend/
│   ├── src/
│   ├── public/
│   ├── package.json
│   └── vite.config.js
│
├── README.md
└── .gitignore

````

---

## ⚙️ How to Run

### 1️⃣ Backend (C++)

Requirements:
- Visual Studio (C++ Build Tools)
- vcpkg installed

```bash
cd backend
````

Compile:

```bash
cl /std:c++17 /EHsc main.cpp Student.cpp StudentManager.cpp ^
/I D:\vcpkg\installed\x64-windows\include ^
/link /LIBPATH:D:\vcpkg\installed\x64-windows\lib ^
drogon.lib trantor.lib jsoncpp.lib
```

Run:

```bash
main.exe
```

Server:

```
http://127.0.0.1:8080
```

---

### 2️⃣ Frontend (React)

```bash
cd frontend
npm install
npm run dev
```

Open:

```
http://localhost:5173
```

---

## 🔗 API Endpoints

### 📥 Get Students

```
GET /students
```

---

### ➕ Add Student

```
POST /students
```

```json
{
  "name": "Ahmed"
}
```

---

### ➕ Add Course

```
POST /students/{id}/courses
```

```json
{
  "courseName": "Math",
  "grade": 90
}
```

---

## 🧪 Testing

* Postman
* Browser (GET requests)

---

## ⚠️ Notes

* Backend must be running first
* CORS enabled for frontend connection
* Data stored in memory (no database yet)

---

## 🔮 Future Improvements

* 🗄️ MongoDB integration
* ✏️ Update/Delete features
* 🔐 Authentication
* 🎨 UI enhancements
* 📊 Dashboard

---

## 👩‍💻 Author

**Rowan Khalil**

```

---

# 💥 لو عايزة تبقى جامدة جدًا (نصيحة)
ضيفي في README:

## 📸 Screenshots
اعملي screenshot:
- إضافة طالب
- عرض الطلاب

---

# 🔥 بصراحة
المشروع ده:
👉 قوي جدًا على GitHub  
👉 ينفع Portfolio  
👉 ويبين إنك فاهم Backend + Frontend 👏


