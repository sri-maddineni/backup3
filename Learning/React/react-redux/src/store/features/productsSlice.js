import { createSlice } from '@reduxjs/toolkit';

const initialState = {
    items: [
        {
            id: 1,
            name: "Wireless Headphones",
            price: 99.99,
            image: "https://via.placeholder.com/150",
            description: "High-quality wireless headphones with noise cancellation"
        },
        {
            id: 2,
            name: "Smart Watch",
            price: 199.99,
            image: "https://via.placeholder.com/150",
            description: "Feature-rich smartwatch with health monitoring"
        },
        {
            id: 3,
            name: "Laptop Backpack",
            price: 49.99,
            image: "https://via.placeholder.com/150",
            description: "Durable and spacious laptop backpack"
        },
        {
            id: 4,
            name: "Wireless Mouse",
            price: 29.99,
            image: "https://via.placeholder.com/150",
            description: "Ergonomic wireless mouse for comfortable use"
        }
    ],
    status: 'idle',
    error: null
};

export const productsSlice = createSlice({
    name: 'products',
    initialState,
    reducers: {
        // Add reducers here if needed
    }
});

export default productsSlice.reducer; 