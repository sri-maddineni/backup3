import { getAnalytics } from "firebase/analytics";
import { initializeApp } from "firebase/app";
import { addDoc, collection, getFirestore } from "firebase/firestore";
import React, { useState } from "react";
import { Link } from "react-router-dom";
import { firebaseConfig } from "../../../assets/apikeys/Apis";

const Request = () => {
  const [date, setDate] = useState("");
  const [topic, setTopic] = useState("");
  const [reason, setReason] = useState("");
  const [errormessage, setErrormessage] = useState("");
  const [name, setName] = useState("");
  const [study, setStudy] = useState("");
  const [dateasked, setDateasked] = useState("")

  const app = initializeApp(firebaseConfig);

  const db = getFirestore(app);

  const Bread = () => {
    return (
      <>
        <nav aria-label="breadcrumb" className="mt-1 mx-1">
          <ol className="breadcrumb">
            <li className="breadcrumb-item">
              <Link to="/">Home</Link>
            </li>

            <li className="breadcrumb-item active" aria-current="page">
              Request for material
            </li>
          </ol>
        </nav>
      </>
    );
  };

  const handleSubmit = async () => {
    setErrormessage(""); // Clear error message if all fields are valid

    if (name == "") {
      setErrormessage("Please Add your name");
      return;
    }

    if (study == "") {
      setErrormessage("Please Add class");
      return;
    }

    if (topic == "") {
      setErrormessage("Please Add topic");
      return;
    }

    if (reason == "") {
      setErrormessage("Please Add reason");
      return;
    }

    if (date == "") {
      setErrormessage("Please Add date");
      return;
    }

    const docData = {
      topic: topic,
      date: date,
      name: name,
      class: study,
      reason: reason,
      dateasked:`${String(new Date(Date.now()).getDate()).padStart(2, '0')} ${String(new Date(Date.now()).getMonth() + 1).padStart(2, '0')} ${new Date(Date.now()).getFullYear()}`

    };

    try {
      const docRef = await addDoc(
        collection(db, "/Docs/TdOF4SjgW0Z6dKPvrpoM/requests"),
        docData
      );
      console.log("Document written with ID: ", docRef.id);
      // Optionally reset form fields here

      setTopic("");
      setDate("");
      setReason("");
      setName("");
      setStudy("");
    } catch (e) {
      console.error("Error adding document: ", e);
      setErrormessage("An error occurred while adding the document.");
    }
  };

  return (
    <>
      <Bread />
      <div
        className="container"
        style={{ display: "flex", flexDirection: "column" }}
      >
        <input
          type="text"
          value={name}
          onChange={(e) => {
            setName(e.target.value);
          }}
          className="p-1 m-1"
          placeholder="Enter your name"
        />
        <input
          type="text"
          value={study}
          onChange={(e) => {
            setStudy(e.target.value);
          }}
          className="p-1 m-1"
          placeholder="Enter your class"
        />
        <input
          type="text"
          value={topic}
          onChange={(e) => {
            setTopic(e.target.value);
          }}
          className="p-1 m-1"
          placeholder="Enter Topic/subject name"
        />
        <input
          type="text"
          value={reason}
          onChange={(e) => {
            setReason(e.target.value);
          }}
          className="p-1 m-1"
          placeholder="Enter purpose like for class x exams"
        />
        <input
          type="text"
          value={date}
          onChange={(e) => {
            setDate(e.target.value);
          }}
          className="p-1 m-1"
          placeholder="Enter date required in dd/month format ex: 29 september"
        />

        <p className="m-1">
          {" "}
          I want material for "{topic}" for my "{reason}" by {date}
        </p>
        <p className="text-danger m-1">{errormessage}</p>
        <div className="text-center">
          <button className="btn btn-primary m-1" onClick={handleSubmit}>
            Submit Request
          </button>
        </div>
      </div>
    </>
  );
};

export default Request;
