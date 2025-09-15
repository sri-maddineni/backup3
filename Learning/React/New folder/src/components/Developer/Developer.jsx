import React from "react";
import styled from "styled-components";
import linkedin from "../../assets/logos/linkedin.png";
import gmail from "../../assets/logos/gmail.png";
import logo from "../../assets/logos/logo.png";
import telegram from "../../assets/logos/telegram.png";
import insta from "../../assets/logos/instagram.png";
import { Link } from "react-router-dom";

const Bread = () => {
  return (
    <nav aria-label="breadcrumb">
      <ol className="breadcrumb">
        <li className="breadcrumb-item">
          <Link to="/">Home</Link>
        </li>
        <li className="breadcrumb-item active" aria-current="page">
          Developer
        </li>
      </ol>
    </nav>
  );
};

const Developer = () => {

  // const test = import.meta.env.VITE_TEST;
  return (
    <Wrapper className="text-center">
      <Bread />
      <div className="profile-section">
        <div className="img">
          <img src={logo} alt="Developer's logo" />
        </div>
        <div className="details">
          <h1>iTKonnects</h1>
          <h3 style={{ fontWeight: "700" }}>CONNECT WITH TECHNOLOGY</h3>

          <div className="card p-2">
            <h4>SRIHARI MADDINENI</h4>
            <h3>
              Android Developer <br /> Full Stack Web Developer
            </h3>
          </div>
        </div>
        <div className="social-icons">
          <a
            href="mailto:itkonnects@gmail.com"
            target="_blank"
            className="icon"
          >
            <img src={gmail} alt="Gmail" />
          </a>
          <a
            href="https://in.linkedin.com/in/srihari-maddineni"
            target="_blank"
            className="icon"
          >
            <img src={linkedin} alt="LinkedIn" />
          </a>
          <a
            href="https://t.me/itkonnects"
            target="_blank"
            rel="noopener noreferrer"
            className="icon"
          >
            <img src={telegram} alt="Telegram" />
          </a>
          <a
            href="https://www.instagram.com/life_hater_sri/"
            target="_blank"
            className="icon"
          >
            <img src={insta} alt="Instagram" />
          </a>
        </div>
        
      </div>
    </Wrapper>
  );
};

const Wrapper = styled.div`
  background-color: #f9f9f9;
  padding: 20px;
  border-radius: 10px;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.1);
  max-width: 600px;
  font-family: "Arial", sans-serif;

  .profile-section {
    text-align: center;
    margin-top: 20px;
  }

  .img img {
    border-radius: 50%;
    height: 120px;
    width: 120px;
    border: 5px solid #e0e0e0;
    margin-bottom: 20px;
    transition: transform 0.3s ease;
  }

  .img img:hover {
    transform: scale(1.1);
  }

  .details h1 {
    font-size: 2rem;
    color: #333;
    margin-bottom: 10px;
  }

  .details h3 {
    font-size: 1.2rem;
    color: #555;
    margin-bottom: 10px;
  }

  .bio {
    font-size: 1rem;
    color: #666;
    margin-top: 10px;
    line-height: 1.5;
    padding: 0 20px;
  }

  .social-icons {
    display: flex;
    justify-content: center;
    margin-top: 20px;
  }

  .icon {
    margin: 0 10px;
    transition: transform 0.3s ease;
  }

  .icon img {
    width: 40px;
    height: 40px;
  }

  .icon:hover {
    transform: scale(1.2);
  }
`;

export default Developer;
