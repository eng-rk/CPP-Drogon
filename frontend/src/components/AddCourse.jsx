import { useState } from "react";

function AddCourse({ onCourseAdded }) {
  const [studentId, setStudentId] = useState("");
  const [courseName, setCourseName] = useState("");
  const [grade, setGrade] = useState("");
  const [message, setMessage] = useState("");

  const handleSubmit = async (e) => {
    e.preventDefault();

    if (!studentId || !courseName.trim() || !grade) {
      setMessage("Please fill all fields");
      return;
    }

    try {
      const res = await fetch(`http://127.0.0.1:8080/students/${studentId}/courses`, {
        method: "POST",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify({
          courseName,
          grade: Number(grade)
        })
      });

      const data = await res.json();
      setMessage(data.message);

      setStudentId("");
      setCourseName("");
      setGrade("");

      if (data.success && onCourseAdded) {
        onCourseAdded();
      }
    } catch (error) {
      console.error(error);
      setMessage("Failed to connect to backend");
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <h2>Add Course & Grade</h2>

      <div className="form-row">
        <input
          type="number"
          placeholder="Student ID"
          value={studentId}
          onChange={(e) => setStudentId(e.target.value)}
        />

        <input
          type="text"
          placeholder="Course name"
          value={courseName}
          onChange={(e) => setCourseName(e.target.value)}
        />

        <input
          type="number"
          placeholder="Grade"
          value={grade}
          onChange={(e) => setGrade(e.target.value)}
        />

        <button type="submit">Add Course</button>
      </div>

      {message && <p className="success-msg">{message}</p>}
    </form>
  );
}

export default AddCourse;