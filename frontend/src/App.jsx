import { useState } from "react";
import AddStudent from "./components/AddStudent";
import AddCourse from "./components/AddCourse";
import StudentsList from "./components/StudentsList";
import "./App.css";

function App() {
  const [refreshKey, setRefreshKey] = useState(0);

  const refreshStudents = () => {
    setRefreshKey((prev) => prev + 1);
  };

  return (
    <div className="app">
      <div className="container">
        <h1 className="title">Student Course Management System</h1>

        <div className="section">
          <AddStudent onStudentAdded={refreshStudents} />
        </div>

        <div className="section">
          <AddCourse onCourseAdded={refreshStudents} />
        </div>

        <div className="section">
          <StudentsList refreshKey={refreshKey} />
        </div>
      </div>
    </div>
  );
}

export default App;