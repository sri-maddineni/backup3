import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";

export const firebaseConfig = {
  // const test = import.meta.env.VITE_TEST;
  apiKey: import.meta.env.VITE_APIKEY,
  authDomain: import.meta.env.VITE_authDomain,
  projectId: import.meta.env.VITE_projectId,
  storageBucket: import.meta.env.VITE_storageBucket,
  messagingSenderId: import.meta.env.VITE_messagingSenderId,
  appId: import.meta.env.VITE_appId,
  measurementId: import.meta.env.VITE_measurementId,
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);
