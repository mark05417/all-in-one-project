import React from 'react';
import { BrowserRouter as Router, Routes, Route, Link } from 'react-router-dom';
import './App.css';

// Navbar component
const Navbar = () => {
  return (
    <nav>
      <ul>
        <li><Link to="/">Home</Link></li>
        <li><Link to="/about">About</Link></li>
        <li><Link to="/contact">Contact</Link></li>
      </ul>
    </nav>
  );
};

// Home component
const Home = () => {
  return (
    <section>
      <h1>Welcome to My Website</h1>
      <p>This is the Home page. Explore the content using the navigation bar.</p>
    </section>
  );
};

// About component
const About = () => {
  return (
    <section>
      <h2>About Us</h2>
      <p>We are building amazing web applications with React!</p>
    </section>
  );
};

// Contact component
const Contact = () => {
  return (
    <section>
      <h2>Contact Us</h2>
      <p>Email: contact@example.com</p>
    </section>
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
    <Router>
      <div className="App">
        <Navbar />
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
          <Route path="/contact" element={<Contact />} />
        </Routes>
        <Footer />
      </div>
    </Router>
  );
}

export default App;
