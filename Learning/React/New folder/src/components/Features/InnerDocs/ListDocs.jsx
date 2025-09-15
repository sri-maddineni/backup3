import React, { useState, useEffect } from "react";
import { Link, useParams } from "react-router-dom";
import { initializeApp } from "firebase/app";
import { getFirestore, collection, getDocs } from "firebase/firestore";
import { firebaseConfig } from "../../../assets/apikeys/Apis";

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const db = getFirestore(app);

const ListDocs = () => {
  const { classId } = useParams();
  const [docs, setDocs] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  const Bread = () => {
    return (
      <>
        <nav aria-label="breadcrumb" className="mt-1 mx-1">
          <ol className="breadcrumb">
            <li className="breadcrumb-item">
              <Link to="/">Home</Link>
            </li>
            <li className="breadcrumb-item active" aria-current="page">
              {classId}
            </li>
          </ol>
        </nav>
      </>
    );
  };

  useEffect(() => {
    const fetchDocs = async () => {
      try {
        const querySnapshot = await getDocs(
          collection(db, "Docs", "folders", classId)
        );
        const documents = querySnapshot.docs.map((doc) => ({
          id: doc.id,
          ...doc.data(),
        }));
        setDocs(documents);
      } catch (err) {
        setError(err.message);
      } finally {
        setLoading(false);
      }
    };

    fetchDocs();
  }, [classId]);

  if (loading) return <div>Loading...</div>;
  if (error) return <div>Error: {error}</div>;

  return (
    <div className="text-center">
      <Bread />
      <h5>
        {docs.length ? docs.length : ""} Document{docs.length > 1 ? "s" : ""}{" "}
        found for : {classId}
      </h5>
      <ul style={{ listStyle: "none", padding: "0" }}>
        {docs.length ? (
          docs.map((doc) => (
            <li key={doc.id}>
              <a
                className="card p-1 m-1"
                style={{
                  display: "flex",
                  flexDirection: "row",
                  justifyContent: "space-between",
                  textDecoration: "none",
                }}
                href={doc.link}
                target="_blank"
              >
                <i className="fa-solid fa-file fa-2x p-1 mx-3"></i>
                <div>
                  <h6 className="mx-3">{doc.topic}</h6>
                  <p>{doc.des ? doc.des : "..."}</p>
                </div>
                <div className="text-center p-2" style={{display:"flex",flexDirection:"column",justifyContent:"center"}}>
                  <button className="btn btn-danger btn-sm">open pdf</button>
                </div>{" "}
              </a>
            </li>
          ))
        ) : (
          <>
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
          </>
        )}
      </ul>
    </div>
  );
};

export default ListDocs;
