import React, { useEffect, useState } from "react";
import { firebaseConfig } from "../../../assets/apikeys/Apis";
import { getAnalytics } from "firebase/analytics";
import { initializeApp } from "firebase/app";
import { addDoc, collection, deleteDoc, doc, getDocs, getFirestore } from "firebase/firestore";
import { Link, useNavigate, useParams } from "react-router-dom";
import { Radio } from "antd";

const AddDoc = () => {
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
  const [docData, setDocdata] = useState("");
  const [des, setDes] = useState("");
  const [topic, setTopic] = useState("");

  const [docs, setDocs] = useState("");

  const [loading, setLoading] = useState(false);

  const [requests, setRequests] = useState([]);
  const [error, setError] = useState("");
  const navigate=useNavigate();

  const fetchDocs = async () => {
    try {
      const querySnapshot = await getDocs(
        collection(db, "Docs", "TdOF4SjgW0Z6dKPvrpoM", "requests")
      );
      const documents = querySnapshot.docs.map((doc) => ({
        id: doc.id,
        ...doc.data(),
      }));
      setRequests(documents);
    } catch (err) {
      setError(err.message);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
   

    fetchDocs();
  }, []);

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
              AddDocs
            </li>
          </ol>
        </nav>
      </>
    );
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

  const handleDelete = async (id) => {
    try {
      // Define the document reference
      const docRef = doc(db, "Docs", "TdOF4SjgW0Z6dKPvrpoM", "requests", id);
      
      // Delete the document
      await deleteDoc(docRef);
      
      console.log(`Document with ID ${id} has been deleted.`);
      fetchDocs();
    } catch (error) {
      console.error("Error removing document: ", error);
    }
  };

  const onChange = (e) => {
    console.log("radio checked", e.target.value);
    setRvalue(e.target.value);
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
        <div
          className="m-1"
          style={{ display: "flex", flexDirection: "column" }}
        >
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
            value={des}
            onChange={(e) => {
              setDes(e.target.value);
            }}
            className="p-1 m-1"
            placeholder="Enter Description"
          />
          <input
            type="text"
            value={link}
            onChange={(e) => {
              setLink(e.target.value);
            }}
            className="p-1 m-1"
            placeholder="Enter link"
          />
          <p className="m-1">
            {" "}
            Adding topic "{topic}" into : {rvalue} folder{" "}
          </p>
          <p className="text-danger m-1">{errormessage}</p>
          <div className="text-center">
            <button className="btn btn-primary m-1" onClick={handleSubmit}>
              Add Document
            </button>
            
          </div>
          <button className="btn btn-warning m-1" onClick={()=>{navigate("/author/docsModify")}}>
              View Documents
            </button>
        </div>
        <hr />
        <div className="requests m-2">
          <h2 className="text-center">{requests.length} Request for Materials</h2>
          {requests.map((req) => (
            <>
              <div className="each m-2 p-2 card">
                <div className="m-2">
                  <p className="px-3 m-0">topic : {req.topic}</p>
                  <p className="px-3 m-0">reason : {req.reason}</p>
                  <p className="px-3 m-0">Requested on : {req.dateasked}</p>
                  <p className="px-3 m-0">date required : {req.date}</p>
                  
                </div>
                <div className="btn btn-danger btn-sm m-1 p-1" onClick={()=>handleDelete(req.id)}>delete</div>
              </div>
            </>
          ))}
        </div>
      </div>
    </>
  );
};

export default AddDoc;
