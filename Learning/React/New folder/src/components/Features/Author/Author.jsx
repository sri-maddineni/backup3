import React, { useState } from "react";
import author from "../../../assets/logos/homeicons/author.jpeg";
import styles from "./author.module.css";
import { Link, useNavigate } from "react-router-dom";

const Bread = () => {
  return (
    <>
      <nav aria-label="breadcrumb" className="mt-1 mx-1">
        <ol className="breadcrumb">
          <li className="breadcrumb-item">
            <Link to="/">Home</Link>
          </li>
          <li className="breadcrumb-item active" aria-current="page">
            Author
          </li>
        </ol>
      </nav>
    </>
  );
};

const Author = () => {
  const [password, setPassword] = useState("");
  const [error, seterror] = useState("");

  const navigate = useNavigate(); // Initialize useNavigate

  const handleLogin = () => {
    if (password === "aaa") {
      navigate("/author/addDocs"); // Navigate to the desired route
    } else {
      seterror("Please enter valid text");
    }
  };
  return (
    <>
      <div>
        <Bread />
        <div className={`${styles.author}`}>
          <img src={author} alt="author" />
        </div>
        <div className="details">
          <strong>
            <p className="text-center text-dark">Velpula Venkat</p>
          </strong>
          <p style={{ margin: "0", padding: "0" }} className="text-center">
            96409 03802
          </p>
        </div>
        <div
          className="text-center"
          style={{
            display: "flex",
            flexDirection: "column",
            justifyContent: "center",
            alignItems: "center",
          }}
        >
          <label htmlFor="">To add materials, please enter text</label>
          <input
            type="text"
            style={{ width: "40%" }}
            className="text-center m-2"
            placeholder="Enter text"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
          />
          <button
            className="btn btn-primary text-center m-2"
            onClick={handleLogin} // Call handleLogin on button click
          >
            Add material
          </button>
          {error && <p className="text-danger">{error}</p>}{" "}
          {/* Display error message */}
        </div>
      </div>
    </>
  );
};

export default Author;
