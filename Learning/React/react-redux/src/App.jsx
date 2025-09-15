import { Provider } from 'react-redux';
import { store } from './store/store';
import Navbar from './components/Navbar';
import ProductList from './components/ProductList';
import Cart from './components/Cart';

function App() {
  return (
    <Provider store={store}>
      <div>
        <Navbar />
        <main className="main-content">
          <div className="container">
            <div style={{ display: 'grid', gridTemplateColumns: '2fr 1fr', gap: '2rem' }}>
              <ProductList />
              <Cart />
            </div>
          </div>
        </main>
      </div>
    </Provider>
  );
}

export default App;
