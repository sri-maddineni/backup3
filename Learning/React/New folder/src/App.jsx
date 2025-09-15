import React from "react";
import { BrowserRouter, Route, Routes } from "react-router-dom";
import Navbar from "./components/Header/Navbar";
import Home from "./components/Features/Home";
import Author from "./components/Features/Author/Author";
import "./App.css";
import ListDocs from "./components/Features/InnerDocs/ListDocs";
import AddDoc from "./components/Features/Add/AddDoc";
import Request from "./components/Features/Request/Request";
import ModifyDocs from "./components/Features/Author/ModifyDocs/ModifyDocs";
import Developer from "./components/Developer/Developer";

export default function App() {
  return (
    <>
      <div className="fixed">
        <Navbar />
      </div>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/author" element={<Author />} />
        <Route path="/listdocs/:classId" element={<ListDocs />} />
        <Route path="/author/addmaterial" element={<ListDocs />} />
        <Route path="/author/addDocs" element={<AddDoc />} />
        <Route path="/request" element={<Request />} />
        <Route path="/author/docsModify" element={<ModifyDocs />} />
        <Route path="/developer" element={<Developer />} />
        
       
      </Routes>
    </>
  );
}
