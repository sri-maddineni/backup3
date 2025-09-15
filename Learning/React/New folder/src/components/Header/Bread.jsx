import { Link } from "react-router-dom";

export const Bread = (props) => {
    return (
      <>
        <nav aria-label="breadcrumb" className="mt-1 mx-1">
          <ol className="breadcrumb">
            <li className="breadcrumb-item">
              <Link to="/">Home</Link>
            </li>
            <li className="breadcrumb-item active" aria-current="page">
              Author
            </li>
          </ol>
        </nav>
      </>
    );
  };
  