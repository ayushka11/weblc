import './App.css'
import React, { useEffect } from 'react';
import { useState } from 'react';
import createModule from "./add.mjs";
import { Scanner } from '@yudiel/react-qr-scanner';

function App() {
  const [retrn, setRetrn] = useState();
  const [name,setName] = useState("");
  const [result,setResult] = useState("");
  const [qR, setQR] = useState(false);
  const [registers, setRegisters] = useState([
    { R_R0: 0, R_R1: 0, R_R2: 0, R_R3: 0, R_R4: 0, R_R5: 0, R_R6: 0, R_R7: 0, R_PC: 0, R_COND: 0, R_COUNT: 0 }
  ]);

  const handleNext = () => {
    retrn(0);
    setRegisters([...registers,    { R_R0: 1, R_R1: 2, R_R2: 3, R_R3: 0, R_R4: 0, R_R5: 0, R_R6: 0, R_R7: 0, R_PC: 0, R_COND: 0, R_COUNT: 0 }
    ])
  };

  const handleExecuteAll = () => {
    retrn(0);
  };

  const stepDown = () =>{
    retrn(1);
  }

  const showQR = () => {
    setQR(!qR);
    document.getElementById("QR").style.display = qR ? "block" : "none";  }
  useEffect(() => { 
    createModule().then((Module) => {    
      setRetrn(() => Module.cwrap("locker", "number", ["string"]));    
    });  }, []);  
      if (!retrn) {    
        return "Loading webassembly...";  
      }

  const headings = Object.keys(registers[0]);
  return (
    <div className="App">
      <button onClick={showQR}>Show QR code</button>
      <div id="QR" style={{display:'none'}}>
        <Scanner
            onResult={(text, result) => console.log(text, result)}
            onError={(error) => console.log(error?.message)}
        />
      </div>
     <div>
      <div>
        <button onClick={handleNext}>Step Up</button>
        <button onClick={handleNext}>Step Down</button>
        <button onClick={handleExecuteAll}>Execute All</button>
      </div>
      <table>
        <thead>
          <tr>
            {headings.map((heading, index) => (
              <th key={index}>{heading}</th>
            ))}
          </tr>
        </thead>
        <tbody>
          {registers.map((register, index) => (
            <tr key={index}>
              {headings.map((heading, index) => (
                <td key={index}>{register[heading]}</td>
              ))}
            </tr>
          ))}
        </tbody>
      </table>
    </div>
    </div>
  );
}

export default App;