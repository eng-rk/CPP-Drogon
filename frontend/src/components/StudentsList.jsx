import { useEffect, useState } from "react";

function StudentsList({ refreshKey }) {
  const [students, setStudents] = useState([]);

  const fetchStudents = async () => {
    try {
      const res = await fetch("http://127.0.0.1:8080/students");
      const data = await res.json();
      setStudents(data);
    } catch (error) {
      console.error(error);
    }
  };

  useEffect(() => {
    fetchStudents();
  }, [refreshKey]);

  return (
    <div className="students-list">
      <h2>Students List</h2>

      {students.length === 0 ? (
        <p className="empty-text">No students yet</p>
      ) : (
        students.map((student) => (
          <div key={student.id} className="student-card">
            <div className="student-name">{student.name}</div>
            <div className="student-id">ID: {student.id}</div>

            {student.courses.length > 0 ? (
              <ul className="course-list">
                {student.courses.map((course, index) => (
                  <li key={index}>
                    {course.courseName} - {course.grade}
                  </li>
                ))}
              </ul>
            ) : (
              <p className="empty-text">No courses added yet</p>
            )}
          </div>
        ))
      )}
    </div>
  );
}

export default StudentsList;