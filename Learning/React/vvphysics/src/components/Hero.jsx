import React from "react";
import { motion } from "framer-motion";
import { styles } from "../styles";
import { ComputersCanvas } from "../components/canvas/Computers";
import resume from "../assets/resumes/sri_m_resume.pdf";

const Hero = () => {
  return (
    <section className="relative w-full h-screen mx-auto">
      <div
        className={`${styles.paddingX} absolute inset-0 top-[120px] max-w-7xl mx-auto flex gap-5 items-start flex-row`}
      >
        <div className="flex flex-col items-center justify-center mt-5">
          <div className="w-5 h-5 rounded-full bg-[#915eff]"></div>
          <div className="w-1 sm:h-80 h-40 violet-gradient"></div>
        </div>

        <div className="">
          <h1 className={`{${styles.heroHeadText}}`}>
            I'm <span className="text-[#915eff]">Srihari Maddineni</span>
          </h1>
          <p className={`${styles.heroSubText} mt-2 text-white-100`}>
            I develop Full stack (MERN Stack) Web apps
            <br />
            Android Applications, User intuitive Interfaces
            <br /> for best user Experience
          </p>
          <div className="flex">
            <a
              href={resume}
              target="_blank"
              rel="noopener noreferrer"
              className="bg-button py-3 px-8 my-5 rounded-xl outline-none w-fit text-primary font-bold shadow-md shadow-primary"
            >
              View resume
            </a>
          </div>
        </div>
      </div>
      {/* <ComputersCanvas /> */}
      {/* <div className="absolute xs:bottom-10 bottom-32 w-full items-center">
        <a href="#about">
          <div className="w-[35px] h-[64px] rounded-3xl border-4 border-secondary flex justify-center items-start p-2">
            <motion.div
              animate={{
                y: [0, 24, 0],
              }}
              transition={{
                duration: 1.5,
                repeat: Infinity,
                repeatType: "loop",
              }}
              className="w-3 h-3 rounded-full bg-secondary mb-1"
            />
          </div>
        </a>
      </div> */}
    </section>
  );
};

export default Hero;
