import { useSelector } from 'react-redux';

const Navbar = () => {
    const cartItems = useSelector((state) => state.cart.items);
    const itemCount = cartItems.reduce((total, item) => total + item.quantity, 0);

    return (
        <nav className="navbar">
            <div className="container">
                <div className="navbar-content">
                    <div className="store-title">
                        E-Commerce Store
                    </div>
                    <div className="cart-icon">
                        <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                            <path d="M3 3h2l.4 2M7 13h10l4-8H5.4M7 13L5.4 5M7 13l-2.293 2.293c-.63.63-.184 1.707.707 1.707H17m0 0a2 2 0 100 4 2 2 0 000-4zm-8 2a2 2 0 11-4 0 2 2 0 014 0z" />
                        </svg>
                        {itemCount > 0 && (
                            <span className="cart-count">
                                {itemCount}
                            </span>
                        )}
                    </div>
                </div>
            </div>
        </nav>
    );
};

export default Navbar; 