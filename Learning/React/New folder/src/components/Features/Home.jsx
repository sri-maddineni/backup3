import React from "react";
import styles from "./Home.module.css";
import { Homeicons } from "../Header/constants";
import bg from "../../assets/logos/homeicons/bg.png";
import { Link } from "react-router-dom";

const Home = () => {
  return (
    <>
      <div>
        <div className={`${styles.cardsdiv}`}>
          {Homeicons.map((item) => (
            <>
              <Link className={`${styles.carder} card`} to={item.link}>
                <img
                  src={item.img}
                  style={{ width: "100px", height: "100px" }}
                  alt="icon"
                />
              </Link>
            </>
          ))}
        </div>
      </div>
    </>
  );
};

export default Home;
