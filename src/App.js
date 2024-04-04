import './App.css'
import React, { useEffect } from 'react';
import { useState } from 'react';
import createModule from "./add.mjs";

function App() {
  const [retrn, setRetrn] = useState();
  const [name,setName] = useState("");
  const [result,setResult] = useState("");
  useEffect(() => { 
    createModule().then((Module) => {    
      setRetrn(() => Module.cwrap("locker", "string", ["string"]));    
    });  }, []);  
      if (!retrn) {    
        return "Loading webassembly...";  
      }

  const handleClick= ()=>{
    setResult(retrn(name))
  }
  return (
    <div className="App">
     <input onChange={e=>{setName(e.target.value)}}></input>
     <button onClick={()=>handleClick()}>Lock/Unlock</button>
     <p>Status:{result}</p>
    </div>
  );
}

export default App;
