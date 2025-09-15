import { useSelector, useDispatch } from 'react-redux';
import { removeFromCart, updateQuantity, clearCart } from '../store/features/cartSlice';

const Cart = () => {
    const cart = useSelector((state) => state.cart);
    const dispatch = useDispatch();

    return (
        <div className="cart-container">
            <h2 className="cart-title">Shopping Cart</h2>
            {cart.items.length === 0 ? (
                <p>Your cart is empty</p>
            ) : (
                <>
                    <div>
                        {cart.items.map((item) => (
                            <div key={item.id} className="cart-item">
                                <div className="cart-item-info">
                                    <img
                                        src={item.image}
                                        alt={item.name}
                                        className="cart-item-image"
                                    />
                                    <div className="cart-item-details">
                                        <h3>{item.name}</h3>
                                        <p className="cart-item-price">${item.price}</p>
                                    </div>
                                </div>
                                <div>
                                    <select
                                        value={item.quantity}
                                        onChange={(e) =>
                                            dispatch(updateQuantity({ id: item.id, quantity: parseInt(e.target.value) }))
                                        }
                                        className="quantity-select"
                                    >
                                        {[1, 2, 3, 4, 5].map((num) => (
                                            <option key={num} value={num}>
                                                {num}
                                            </option>
                                        ))}
                                    </select>
                                    <button
                                        onClick={() => dispatch(removeFromCart(item.id))}
                                        className="remove-btn"
                                    >
                                        Remove
                                    </button>
                                </div>
                            </div>
                        ))}
                    </div>
                    <div className="cart-total">
                        <span>Total:</span>
                        <span>${cart.total.toFixed(2)}</span>
                    </div>
                    <button
                        onClick={() => dispatch(clearCart())}
                        className="clear-cart-btn"
                    >
                        Clear Cart
                    </button>
                </>
            )}
        </div>
    );
};

export default Cart; 