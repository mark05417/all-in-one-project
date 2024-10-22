// src/App.js
import React, { useState } from 'react';
import { auth, googleProvider, microsoftProvider, signInWithPopup } from './firebase';

import { getAuth, fetchSignInMethodsForEmail } from "firebase/auth";

function App() {
  const [user, setUser] = useState(null);

  const auth = getAuth();
  const email = "user@example.com"; // 錯誤中提供的電子郵件地址

  const signInWithGoogle = async () => {
    try {
      const result = await signInWithPopup(auth, googleProvider);
      setUser(result.user);
    } catch (error) {
      console.error('Google sign-in error:', error);
    }
  };

  const signInWithMicrosoft = async () => {
    try {
      const result = await signInWithPopup(auth, microsoftProvider);
      setUser(result.user);
    } catch (error) {
      console.error('Microsoft sign-in error:', error);
    }
  };

  const signOut = () => {
    auth.signOut();
    setUser(null);
  };

  return (
    <div className="App">
      <h1>OAuth Login Example</h1>
      {user ? (
        <div>
          <h2>Welcome, {user.displayName}</h2>
          <img src={user.photoURL} alt="User Avatar" />
          <p>Email: {user.email}</p>
          <button onClick={signOut}>Sign Out</button>
        </div>
      ) : (
        <div>
          <button onClick={signInWithGoogle}>Sign in with Google</button>
          <button onClick={signInWithMicrosoft}>Sign in with Microsoft</button>
        </div>
      )}
    </div>
  );
}

export default App;
