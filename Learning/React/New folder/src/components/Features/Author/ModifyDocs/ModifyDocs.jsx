import React, { useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { firebaseConfig } from "../../../../assets/apikeys/Apis";
import { getAnalytics } from "firebase/analytics";
import {
  collection,
  deleteDoc,
  doc,
  getDocs,
  getFirestore,
} from "firebase/firestore";
import { initializeApp } from "firebase/app";
import { Radio } from "antd";

const ModifyDocs = () => {
  const params = useParams();
  const password = params.pword;

  // Initialize Firebase
  const app = initializeApp(firebaseConfig);
  const analytics = getAnalytics(app);

  const [link, setLink] = useState("");
  const [bclass, setBclass] = useState("");
  const [errormessage, setErrormessage] = useState("");

  const db = getFirestore(app);

  const [rvalue, setRvalue] = useState("");
  const [classId, setClassId] = useState("");
  const [docData, setDocdata] = useState("");
  const [des, setDes] = useState("");
  const [topic, setTopic] = useState("");

  const [docs, setDocs] = useState("");

  const [loading, setLoading] = useState(false);

  const [requests, setRequests] = useState([]);
  const [error, setError] = useState("");
  const navigate = useNavigate();

  const onChange = (e) => {
    console.log("radio checked", e.target.value);
    setRvalue(e.target.value);
  };

  const handleSubmit = async () => {
    // Ensure that link and class are both provided
    if (link.trim() === "") {
      setErrormessage("Please enter a link.");
      return;
    }

    if (rvalue.length === 0) {
      setErrormessage("Please select a class.");
      return;
    }

    setErrormessage(""); // Clear error message if all fields are valid

    const docData = {
      link: link,
      class: rvalue,
      topic: topic,
      des: des,
    };

    try {
      const docRef = await addDoc(
        collection(db, "Docs", "folders", rvalue),
        docData
      );
      console.log("Document written with ID: ", docRef.id);
      // Optionally reset form fields here
      setLink("");
      setRvalue("");
      setTopic("");
      setDes("");
    } catch (e) {
      console.error("Error adding document: ", e);
      setErrormessage("An error occurred while adding the document.");
    }
  };

  const radioItems = [
    {
      title: "class 8",
      valuer: "class8",
    },
    {
      title: "class 9",
      valuer: "class9",
    },
    {
      title: "class 10",
      valuer: "class10",
    },
    {
      title: "DSC",
      valuer: "dsc",
    },
    {
      title: "Railway",
      valuer: "railway",
    },
    {
      title: "Navodaya",
      valuer: "Navodaya",
    },
    {
      title: "Police",
      valuer: "Police",
    },
    {
      title: "chekumuki",
      valuer: "chekumuki",
    },
  ];

  const fetchDocs = async (rvalue) => {
    try {
      setLoading(true);
      const querySnapshot = await getDocs(
        collection(db, "Docs", "folders", rvalue)
      );
      const documents = querySnapshot.docs.map((doc) => ({
        id: doc.id,
        ...doc.data(),
      }));
      setDocs(documents);
    } catch (err) {
      console.log(err.message);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    fetchDocs(rvalue);
  }, [rvalue]);

  const handleDelete = async (id) => {
    try {
      setLoading(true);
      // Define the document reference
      const docRef = doc(db, "Docs", "folders", rvalue, id);

      // Delete the document
      await deleteDoc(docRef);

      console.log(`Document with ID ${id} has been deleted.`);
      fetchDocs(rvalue);
    } catch (error) {
      console.error("Error removing document: ", error);
    } finally {
      setLoading(false);
    }
  };

  const Bread = () => {
    return (
      <>
        <nav aria-label="breadcrumb" className="mt-1 mx-1">
          <ol className="breadcrumb">
            <li className="breadcrumb-item">
              <Link to="/">Home</Link>
            </li>
            <li className="breadcrumb-item">
              <Link to="/author">Author</Link>
            </li>
            <li className="breadcrumb-item active" aria-current="page">
              ModifyDocs
            </li>
          </ol>
        </nav>
      </>
    );
  };

  return (
    <>
      <Bread />
      <div className="container">
        <Radio.Group
          onChange={onChange}
          value={rvalue}
          className="m-1 p-1"
          style={{ display: "flex", flexDirection: "row", flexWrap: "wrap" }}
        >
          {radioItems.map((item) => (
            <Radio key={item.valuer} value={item.valuer}>
              {item.title}
            </Radio>
          ))}
        </Radio.Group>

        <hr />
        <h5>
          {docs.length ? docs.length : ""} Document{docs.length > 1 ? "s" : ""}{" "}
          found for : {rvalue}
        </h5>
        {loading ? (
          "Loading..."
        ) : (
          <ul style={{ listStyle: "none", padding: "0" }}>
            {docs.length ? (
              docs.map((doc) => (
                <li key={doc.id}>
                  <div
                    className="card p-1 m-1"
                    style={{
                      display: "flex",
                      flexDirection: "row",
                      justifyContent: "space-between",
                    }}
                  >
                    <a
                      style={{
                        display: "flex",
                        flexDirection: "row",
                        textDecoration: "none",

                        // Make sure it fills the available space except for the delete button
                      }}
                      href={doc.link}
                      target="_blank"
                    >
                      <i className="fa-solid fa-file fa-2x p-1 mx-3 text-dark"></i>
                      <div className="text-dark">
                        <h6
                          className="mx-3"
                          style={{ wordBreak: "break-word" }}
                        >
                          {doc.topic}
                        </h6>

                        <p>{doc.des ? doc.des : "..."}</p>
                      </div>
                    </a>
                    <div
                      className="text-center p-2"
                      style={{
                        display: "flex",
                        flexDirection: "row",
                        justifyContent: "space-around",
                      }}
                    >
                      <div>
                        <button className="btn btn-primary btn-sm m-1">
                          <a
                            href={doc.link}
                            target="_blank"
                            style={{ textDecoration: "none", color: "white" }}
                          >
                            Open
                          </a>
                        </button>
                      </div>
                      <div
                        className="fa-solid fa-trash-can text-danger m-3"
                        onClick={() => {
                          handleDelete(doc.id);
                        }}
                      ></div>
                    </div>
                  </div>
                </li>
              ))
            ) : (
              <div
                className="text-center"
                style={{
                  display: "flex",
                  alignItems: "center",
                  justifyItems: "center",
                  justifyContent: "center",
                }}
              >
                No Materials found
              </div>
            )}
          </ul>
        )}
      </div>
    </>
  );
};

export default ModifyDocs;
