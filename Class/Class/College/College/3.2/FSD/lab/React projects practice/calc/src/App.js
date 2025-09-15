import React, { useState } from 'react';
import './App.css'

function Calculator() {
  const [input, setInput] = useState('');
  const [result, setResult] = useState('');

  const handleButtonPress = (value) => {
    setInput(input + value);
  };

  const handleEqualPress = () => {
    try {
      setResult(eval(input));
    } catch (error) {
      setResult('Error');
    }
  };

  const handleClearPress = () => {
    setInput('');
    setResult('');
  };

  return (
    <div className="calculator">
      <input type="text" value={input} readOnly />
      <br></br>
      <button onClick={() => handleButtonPress('1')}>1</button>
      <button onClick={() => handleButtonPress('2')}>2</button>
      <button onClick={() => handleButtonPress('3')}>3</button>
      
      <button onClick={() => handleButtonPress('+')}>+</button>
      <br></br>
      <button onClick={() => handleButtonPress('4')}>4</button>
      <button onClick={() => handleButtonPress('5')}>5</button>
      <button onClick={() => handleButtonPress('6')}>6</button>
      
      <button onClick={() => handleButtonPress('-')}>-</button>
      <br></br>
      <button onClick={() => handleButtonPress('7')}>7</button>
      <button onClick={() => handleButtonPress('8')}>8</button>
      <button onClick={() => handleButtonPress('9')}>9</button>
      
      <button onClick={() => handleButtonPress('*')}>*</button>
      <br></br>
      <button onClick={() => handleButtonPress('0')}>0</button>
      <button onClick={() => handleEqualPress()}>=</button>
      <button onClick={() => handleButtonPress('/')}>/</button>
      <button onClick={() => handleClearPress()}>Clear</button>
      <div className="result">{result}</div>
    </div>
  );
}

export default Calculator;
