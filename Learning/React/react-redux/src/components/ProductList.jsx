import { useSelector, useDispatch } from 'react-redux';
import { addToCart } from '../store/features/cartSlice';

const ProductList = () => {
    const products = useSelector((state) => state.products.items);
    const dispatch = useDispatch();

    return (
        <div className="product-grid">
            {products.map((product) => (
                <div key={product.id} className="product-card">
                    <img
                        src={product.image}
                        alt={product.name}
                        className="product-image"
                    />
                    <div className="product-info">
                        <h3 className="product-title">{product.name}</h3>
                        <p className="product-description">{product.description}</p>
                        <div className="product-price">${product.price}</div>
                        <button
                            onClick={() => dispatch(addToCart(product))}
                            className="add-to-cart-btn"
                        >
                            Add to Cart
                        </button>
                    </div>
                </div>
            ))}
        </div>
    );
};

export default ProductList; 