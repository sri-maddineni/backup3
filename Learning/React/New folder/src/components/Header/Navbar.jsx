import React, { useState } from "react";
import styles from "./Navbar.module.css";
import logor from "../../assets/logos/logo-white.svg";
import menu from "../../assets/logos/menu.svg";
import close from "../../assets/logos/close.svg";
import { navLinks } from "./constants";
import { Link } from "react-router-dom";

const Navbar = () => {
  const [active, setActive] = useState(false);

  return (
    <nav className={`${styles.navbar} bg-dark`}>
      <div className={styles.navbarContainer}>
        <Link
          to="/"
          onClick={() => {
            setActive(false);
          }}
          className={styles.navbarLogo}
        >
          <img src={logor} alt="Logo" className={styles.Applogo} />
          Venkat Physics
        </Link>
        <button
          className={styles.navbarToggler}
          onClick={() => setActive(!active)}
          id="navbar-toggler"
        >
          <img src={active ? close : menu} alt="menu" />
        </button>
        <ul
          className={`${styles.navbarMenu} ${active ? styles.active : ""}`}
          id="navbar-menu"
        >
          {navLinks.map((item) => (
            <>
              <li className={styles.navbarItem} key={item.id}>
                {" "}
                <Link
                  onClick={() => setActive(false)}
                  to={`${item.link}`}
                  className={`${styles.navbarLink}`}
                >
                  {item.title}
                </Link>{" "}
              </li>
            </>
          ))}
        </ul>
      </div>
    </nav>
  );
};

export default Navbar;
