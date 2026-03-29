import { useState } from "react";

function AddStudent({ onStudentAdded }) {
  const [name, setName] = useState("");
  const [message, setMessage] = useState("");

  const handleSubmit = async (e) => {
    e.preventDefault();

    if (!name.trim()) {
      setMessage("Please enter student name");
      return;
    }

    try {
      const res = await fetch("http://127.0.0.1:8080/students", {
        method: "POST",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify({ name })
      });

      const data = await res.json();
      setMessage(data.message);
      setName("");

      if (data.success && onStudentAdded) {
        onStudentAdded();
      }
    } catch (error) {
      console.error(error);
      setMessage("Failed to connect to backend");
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <h2>Add Student</h2>

      <div className="form-row">
        <input
          type="text"
          placeholder="Enter student name"
          value={name}
          onChange={(e) => setName(e.target.value)}
        />
        <button type="submit">Add</button>
      </div>

      {message && <p className="success-msg">{message}</p>}
    </form>
  );
}

export default AddStudent;