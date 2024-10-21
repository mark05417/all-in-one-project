import React from 'react';
import './App.css';

// Navbar component
const Navbar = () => {
  return (
    <nav>
      <ul>
        <li><a href="#home">Home</a></li>
        <li><a href="#about">About</a></li>
        <li><a href="#contact">Contact</a></li>
      </ul>
    </nav>
  );
};

// Main content component
const Main = () => {
  return (
    <main>
      <section id="home">
        <h1>Welcome to My Website</h1>
        <p>This is a simple React-based website structure.</p>
      </section>
      <section id="about">
        <h2>About Us</h2>
        <p>We are building amazing web applications with React!</p>
      </section>
      <section id="contact">
        <h2>Contact Us</h2>
        <p>Email: contact@example.com</p>
      </section>
    </main>
  );
};

// Footer component
const Footer = () => {
  return (
    <footer>
      <p>© 2024 My Website. All Rights Reserved.</p>
    </footer>
  );
};

function App() {
  return (
    <div className="App">
      <Navbar />
      <Main />
      <Footer />
    </div>
  );
}

export default App;
