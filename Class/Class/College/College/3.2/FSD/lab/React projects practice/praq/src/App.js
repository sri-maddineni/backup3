import { useState } from "react";
import "./App.css";

const qs = [
  {
    q: "who are you?",
    o: ["student", "worker", "employee"],
    a: "student",
  },
  {
    q: "who are you?",
    o: ["student", "worker", "employee"],
    a: "student",
  },
  {
    q: "who are you?",
    o: ["student", "worker", "employee"],
    a: "student",
  },
];

function App() {
  const [currq, setcurrq] = useState(0);
  const [score, setscore] = useState(0);
  const [showscore, setshowscore] = useState(false);

  const oclick = (selected) => {
    if (selected === qs[currq].a) {
      setscore(score + 1);
    }

    const nq = currq + 1;

    if (nq < qs.length) {
      setcurrq(nq);
    } else {
      setshowscore(true);
    }
  };

  return (
    <div className="app">
      {showscore ? (
        <div className="scoresec">
          you scored {score}/{qs.length}
        </div>
      ) : (
        <>
          <div className="qsec">
            <div className="qcount">
              Question {currq + 1}/{qs.length}
            </div>
            <div className="qtext">{qs[currq].q}</div>
          </div>
          <div className="asec">
            {qs[currq].o.map((option)=>(
              <button key={option}
              onClick={()=>oclick(option)}>
                {option}
              </button>
            ))}
          </div>
        </>
      )}
    </div>
  );
}

export default App;
