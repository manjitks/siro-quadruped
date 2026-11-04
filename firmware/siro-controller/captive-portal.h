#pragma once

#include <Arduino.h>

// ======================================================================
// --- WEB INTERFACE HTML ---
// ======================================================================

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Siro · Robot Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta charset="UTF-8">
  <style>
:root{--content-color:#e87551;--ink:#172d30;--muted:#6b7c7c;--line:#dce4df;--paper:#fffefa;--green:#27665b;color-scheme:light}
*{box-sizing:border-box}body{margin:0;background:#f1f3ed;color:var(--ink);font-family:-apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif;font-size:15px;line-height:1.5}button,input,select{font:inherit}button{cursor:pointer;touch-action:manipulation;border:1px solid var(--line);border-radius:14px;background:var(--paper);color:var(--ink);padding:12px 17px;min-height:46px;font-weight:600;transition:background .15s,transform .15s}button:hover{background:#eaf0e9}button:active{transform:translateY(1px)}button:focus-visible,input:focus-visible,summary:focus-visible,select:focus-visible{outline:3px solid #e8755180;outline-offset:3px}button:disabled{opacity:.5}input[type=range]{accent-color:var(--green);width:100%;min-height:32px}input[type=checkbox]{accent-color:var(--green);width:20px;height:20px}
.shell{max-width:1180px;padding:28px 26px 48px;margin:auto}.topbar{display:flex;align-items:center;justify-content:space-between;gap:14px;margin-bottom:26px}.brand{display:flex;gap:12px;align-items:center;font-weight:800;font-size:23px;letter-spacing:-1px}.brandmark{display:grid;place-items:center;background:var(--ink);color:#f3b49c;width:44px;height:44px;border-radius:15px;font-size:25px}.badge,.eyebrow{font-size:11px;font-weight:750;letter-spacing:1.7px;text-transform:uppercase}.badge{border:1px solid var(--line);padding:8px 12px;border-radius:30px;color:var(--muted);letter-spacing:.6px}.heading{display:flex;justify-content:space-between;align-items:end;gap:24px;margin:20px 0 28px}h1{font-size:clamp(32px,5vw,48px);line-height:1.12;letter-spacing:-2px;margin:8px 0 12px;font-weight:750}p{margin:0;color:var(--muted)}.eyebrow{color:var(--green)}.workspace{display:grid;grid-template-columns:1.5fr 1fr;gap:22px;align-items:start}.card{background:var(--paper);border:1px solid var(--line);border-radius:25px;padding:25px;box-shadow:0 7px 24px #172d3004}.card-head{display:flex;align-items:center;justify-content:space-between;gap:10px;margin-bottom:16px}h2{font-size:20px;letter-spacing:-.5px;margin:0}h3{margin:0 0 18px;font-size:23px}.micro{color:var(--muted);font-size:12px}.drive-layout{display:grid;grid-template-columns:1fr 1fr;align-items:center;gap:18px}.robot-stage{background:radial-gradient(ellipse at 50% 80%,#d9e6db,transparent 62%);border-radius:20px;text-align:center;padding:22px 0}.robot-stage svg{width:100%;max-width:240px;height:190px}.robot-caption{font-size:12px;letter-spacing:1px;color:var(--green)}.dpad{display:grid;grid-template-columns:repeat(3,58px);grid-template-rows:repeat(3,58px);gap:7px;justify-content:center;touch-action:none}.dpad button{padding:0;border-radius:16px;background:#f0f3ec;font-size:21px;touch-action:none}.dpad button:active{background:var(--green);color:white}.dpad .center{font-size:12px;color:var(--muted);display:grid;place-items:center}.dpad [data-drive=forward]{grid-column:2;grid-row:1}.dpad [data-drive=left]{grid-column:1;grid-row:2}.dpad [data-drive=right]{grid-column:3;grid-row:2}.dpad [data-drive=backward]{grid-column:2;grid-row:3}.stop{background:#a94436;color:white;border-color:transparent;min-height:54px;width:100%;margin-top:22px;letter-spacing:.5px}.stop:hover{background:#8d382d}.instruction{font-size:12px;text-align:center;margin-top:11px}.cycle-row,.quick-row{display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-top:18px}.cycle-row button{font-size:12px}.quick-row button{background:#edf3ed;border-color:transparent}.pose-grid{display:grid;grid-template-columns:repeat(3,1fr);gap:9px;margin:18px 0}.pose-grid button{padding:12px 7px;font-size:13px}.pose-grid button span{display:block;font-size:20px;line-height:1.5;margin-bottom:3px}.activity{display:flex;gap:10px;align-items:center;padding:14px 16px;background:#eef3ec;border-radius:15px;margin-top:17px;font-size:12px;color:var(--green)}.dot{width:7px;height:7px;border-radius:50%;background:#76a389;flex-shrink:0}.wide{grid-column:1/-1}.tuning{display:grid;grid-template-columns:repeat(3,1fr);gap:24px;margin-top:20px}.tuning label{display:grid;gap:8px;font-size:13px}.tuning output{font-size:12px;color:var(--green);font-variant-numeric:tabular-nums}.toggle{display:flex;align-items:center;gap:10px;margin-top:18px;font-size:12px;color:var(--muted)}details summary{cursor:pointer;font-size:13px;font-weight:600;list-style:none}details summary:after{content:' +';float:right;color:var(--muted)}details[open] summary:after{content:' −'}.more-poses{display:grid;grid-template-columns:repeat(3,1fr);gap:8px;margin-top:12px}.more-poses button{font-size:12px;padding:9px}.gamepad-status{color:var(--muted);font-size:12px;margin-top:15px}.gamepad-status.connected{color:var(--green)}.footer{display:flex;justify-content:space-between;gap:12px;margin-top:24px;font-size:11px;color:var(--muted)}.text-button{background:transparent;border:0;padding:8px;min-height:36px;font-size:12px}.settings-panel{display:none;position:fixed;inset:0;background:#132b2bb3;z-index:20;overflow:auto;padding:24px;backdrop-filter:blur(5px)}.settings-content{max-width:520px;margin:10px auto;background:var(--paper);padding:28px;border-radius:25px;box-shadow:0 20px 80px #0003}.settings-section{border-bottom:1px solid var(--line);padding:12px 0 22px;margin-bottom:12px}.settings-section h4{margin:10px 0 15px}.settings-section>label{display:block;font-size:13px;color:var(--muted);margin:12px 0 5px}.settings-section input:not([type=checkbox]):not([type=range]),.settings-section select{width:100%;padding:10px;border:1px solid var(--line);border-radius:10px;background:white;color:var(--ink)}.btn-save{background:var(--green);color:white;width:100%;margin-top:16px}.btn-close{width:100%;margin-top:10px}.motor-slider{margin:15px 0}.motor-slider label{display:flex;justify-content:space-between;font-size:13px}.settings-section #wifiStatus{color:var(--muted)!important}
/* Touch controls: keep glyphs from selecting and make press states obvious. */
button,button *,svg{-webkit-user-select:none;user-select:none;-webkit-touch-callout:none;-webkit-user-drag:none;-webkit-tap-highlight-color:transparent}
button{box-shadow:0 2px 0 #1b423512;transition:background .14s,transform .14s,box-shadow .14s}
button:hover{transform:translateY(-1px);box-shadow:0 4px 10px #1b42351c}
button:active{transform:translateY(1px);box-shadow:none}
.dpad button{border:1px solid #d4e0d7;background:linear-gradient(180deg,#fffefa,#edf3ed);box-shadow:0 4px 0 #d9e2da;font-size:25px;font-weight:800;color:#244e46}
.dpad button:hover{background:#e1eee5}
.dpad button:active,.dpad button.is-held{background:#27665b;color:#fff;border-color:#27665b;transform:translateY(2px);box-shadow:0 1px 0 #1b493f}
.quick-row button,.pose-grid button,.cycle-row button{border-color:#dbe5dc;background:#f7f8f2;box-shadow:0 2px 0 #dce5dc}
.quick-row button:hover,.pose-grid button:hover,.cycle-row button:hover{background:#eaf2e9;border-color:#b8cec0}
.stop{box-shadow:0 4px 0 #81382e;font-weight:800}
.stop:active{background:#8d382d;transform:translateY(2px);box-shadow:0 1px 0 #81382e}
@media(max-width:720px){.shell{padding:18px 15px 30px}.workspace{grid-template-columns:1fr}.card{padding:20px;border-radius:21px}.heading{margin:22px 0}.heading>p{display:none}.tuning{gap:16px;grid-template-columns:1fr}.heading h1{letter-spacing:-1.5px}.badge{font-size:10px}.footer{font-size:10px}.settings-panel{padding:12px}.drive-layout{gap:6px}.robot-stage svg{height:160px}.dpad{grid-template-columns:repeat(3,51px);grid-template-rows:repeat(3,51px);gap:5px}}
@media(max-width:420px){.brand .badge{display:none}.drive-layout{grid-template-columns:minmax(0,1fr) 163px}.robot-caption{font-size:9px}.cycle-row button{padding:10px 5px;font-size:11px}}
@media(prefers-reduced-motion:reduce){*{transition:none!important}}
</style>
</head>
<body><main class="shell"><header class="topbar"><div class="brand"><span class="brandmark">s.</span>Siro<span class="badge">Robot companion</span></div><button class="text-button" onclick="openSettings()">Settings &#9881;</button></header>
<div class="heading"><div><div class="eyebrow">A little robot. A lot of personality.</div><h1>Let’s make moves.</h1><p>Your companion’s controls, all in one place.</p></div><p class="micro">ESP32 + PCA9685<br>Local control portal</p></div>
<div class="workspace"><section class="card"><div class="card-head"><h2>Take the lead</h2><span class="badge">Hold to move</span></div><div class="drive-layout"><div class="robot-stage"><svg viewBox="0 0 260 200" fill="none" aria-hidden="true"><ellipse cx="130" cy="174" rx="78" ry="10" fill="#c4d7c9"/><path d="M60 120L46 160L66 166L84 130M180 130L195 167L214 158L198 119" stroke="#294d47" stroke-width="14" stroke-linecap="round" stroke-linejoin="round"/><path d="M81 139L74 176M177 139L183 176" stroke="#547970" stroke-width="13" stroke-linecap="round"/><rect x="62" y="69" width="137" height="79" rx="25" fill="#547970"/><path d="M79 79L73 35L108 57M153 57L190 35L183 79" fill="#e8a287" stroke="#294d47" stroke-width="7" stroke-linejoin="round"/><rect x="73" y="55" width="115" height="80" rx="26" fill="#f6c1a7"/><rect x="87" y="75" width="88" height="43" rx="16" fill="#193e39"/><path d="M104 98Q110 87 116 98M147 98Q153 87 159 98" stroke="#d3f1d5" stroke-width="5" stroke-linecap="round"/><path d="M124 117Q132 124 140 117" stroke="#915d49" stroke-width="3" stroke-linecap="round"/></svg><div class="robot-caption">MEET SIRO</div></div><div class="dpad"><button data-drive="forward" aria-label="Walk forward">↑</button><button data-drive="left" aria-label="Turn left">↶</button><div class="center" style="grid-column:2;grid-row:2">HOLD</div><button data-drive="right" aria-label="Turn right">↷</button><button data-drive="backward" aria-label="Walk backward">↓</button></div></div><button class="stop" onclick="stop()">■ &nbsp; STOP MOVEMENT</button><p class="instruction">Hold an arrow to move. Release to stop.</p><div class="cycle-row"><button onclick="move('forward',true)">↑ &nbsp; One forward cycle</button><button onclick="move('backward',true)">↓ &nbsp; One backward cycle</button></div><div class="activity" role="status"><span class="dot"></span><span id="controlActivity">Choose a movement or a pose</span></div></section>
<section class="card"><div class="card-head"><h2>A little personality</h2><span class="micro">Poses & gestures</span></div><p class="micro">The familiar favourites.</p><div class="quick-row"><button onclick="pose('stand')">Stand tall</button><button onclick="pose('rest')">Take a rest</button></div><div class="pose-grid"><button onclick="pose('wave')"><span aria-hidden="true">✋</span>Wave</button><button onclick="pose('dance')"><span aria-hidden="true">♫</span>Dance</button><button onclick="pose('bow')"><span aria-hidden="true">↘</span>Bow</button><button onclick="pose('cute')"><span aria-hidden="true">♡</span>Cute</button><button onclick="pose('shake')"><span aria-hidden="true">↔</span>Shake</button><button onclick="pose('pushup')"><span aria-hidden="true">⇵</span>Pushup</button></div><details><summary>More moves</summary><div class="more-poses"><button onclick="pose('swim')">Swim</button><button onclick="pose('point')">Point</button><button onclick="pose('freaky')">Freaky</button><button onclick="pose('worm')">Worm</button><button onclick="pose('shrug')">Shrug</button><button onclick="pose('dead')">Dead</button><button onclick="pose('crab')">Crab</button></div></details><div id="gamepadStatus" class="gamepad-status">Gamepad disconnected</div></section>
<section class="card wide"><details><summary>Tune the walk <span class="micro">&nbsp; · stride, lift & timing</span></summary><div class="tuning"><label>Stride<input type="range" min="5" max="25" value="15" onchange="fetch('/setSettings?gaitStride='+this.value);this.nextElementSibling.textContent=this.value+'°'"><output>15°</output></label><label>Foot lift<input type="range" min="10" max="55" value="45" onchange="fetch('/setSettings?gaitLift='+this.value);this.nextElementSibling.textContent=this.value+'°'"><output>45°</output></label><label>Step timing<input type="range" min="100" max="500" value="100" step="20" onchange="fetch('/setSettings?frameDelay='+this.value);this.nextElementSibling.textContent=this.value+' ms'"><output>100 ms</output></label></div><label class="toggle"><input type="checkbox" onchange="fetch('/setSettings?reverseWalk='+(this.checked?1:0))">Reverse walking direction</label></details></section></div><footer class="footer"><span>Small steps. Big character.</span><button class="text-button" onclick="openMotorControl()">Individual servo controls ↗</button></footer></main>
  <div id="settingsPanel" class="settings-panel">
    <div class="settings-content">
      <h3>Settings</h3>
      
      <div class="settings-section">
        <h4>Animation Parameters</h4>
        <label>Frame Delay (ms):</label>
        <input type="number" id="frameDelay" min="1" max="1000" step="1">
        <label>Walk Cycles:</label>
        <input type="number" id="walkCycles" min="1" max="50" step="1">
      </div>

      <div class="settings-section">
        <h4>Motor Settings</h4>
        <label>Motor Current Delay (ms):</label>
        <input type="number" id="motorCurrentDelay" min="0" max="500" step="1">
        <label>Motor Speed:</label>
        <select id="motorSpeed">
          <option value="slow">Slow</option>
          <option value="medium" selected>Medium</option>
          <option value="fast">Fast</option>
        </select>
      </div>

      <div class="settings-section">
        <h4>Theme</h4>
        <label>Accent Color:</label>
        <select id="themeColor">
          <option value="#ff8c42">Orange (Default)</option>
          <option value="#66d9ef">Cyan</option>
          <option value="#a8dadc">Light Blue</option>
          <option value="#2ecc71">Green</option>
          <option value="#e74c3c">Red</option>
          <option value="#9b59b6">Purple</option>
          <option value="#f39c12">Yellow</option>
          <option value="#e91e63">Pink</option>
          <option value="custom">Custom</option>
        </select>
        <input type="color" id="customColor" value="#ff8c42" style="margin-top: 10px; display: none;">
      </div>

      <div class="settings-section">
        <h4>WiFi / Network</h4>
        <div id="wifiStatus" style="font-size:13px; color:#ccc; margin-bottom:10px;">Checking&hellip;</div>
        <label>Network:</label>
        <select id="wifiSsid">
          <option value="">&mdash; scan for networks &mdash;</option>
        </select>
        <label style="margin-top:12px;">
          <input type="checkbox" id="wifiManual" style="width:auto; margin-right:8px;" onchange="toggleManualSsid()">
          Enter name manually (hidden network)
        </label>
        <input type="text" id="wifiSsidManual" placeholder="Network name" style="display:none;">
        <label>Password:</label>
        <input type="password" id="wifiPass" placeholder="WiFi password">
        <button class="btn-settings" style="width:100%; margin-top:12px;" onclick="scanWifi()">Scan for Networks</button>
        <button class="btn-settings" style="width:100%; margin-top:8px;" onclick="connectWifi()">Connect</button>
        <div id="wifiResult" style="font-size:13px; margin-top:10px; min-height:18px;"></div>
      </div>

      <button class="btn-settings" style="width: 100%; margin-top: 20px;" onclick="openMotorControl()">Manual Motor Control</button>

      <button class="btn-save" onclick="saveSettings()">Save Settings</button>
      <button class="btn-close" onclick="closeSettings()">Close</button>
    </div>
  </div>

  <div id="motorControlPanel" class="settings-panel">
    <div class="settings-content">
      <h3>Manual Motor Control</h3>
      
      
      <div class="settings-section">
        <div class="motor-controls">
          <div class="motor-slider">
            <label><span>S0 R1</span><span id="m1val">90&deg;</span></label>
            <input type="range" id="motor1" min="0" max="180" value="90" oninput="updateMotor(1, this.value)">
          </div>
          <div class="motor-slider">
            <label><span>S1 R2</span><span id="m2val">90&deg;</span></label>
            <input type="range" id="motor2" min="0" max="180" value="90" oninput="updateMotor(2, this.value)">
          </div>
          <div class="motor-slider">
            <label><span>S2 L1</span><span id="m3val">90&deg;</span></label>
            <input type="range" id="motor3" min="0" max="180" value="90" oninput="updateMotor(3, this.value)">
          </div>
          <div class="motor-slider">
            <label><span>S3 L2</span><span id="m4val">90&deg;</span></label>
            <input type="range" id="motor4" min="0" max="180" value="90" oninput="updateMotor(4, this.value)">
          </div>
          <div class="motor-slider">
            <label><span>S4 R4</span><span id="m5val">90&deg;</span></label>
            <input type="range" id="motor5" min="0" max="180" value="90" oninput="updateMotor(5, this.value)">
          </div>
          <div class="motor-slider">
            <label><span>S5 R3</span><span id="m6val">90&deg;</span></label>
            <input type="range" id="motor6" min="0" max="180" value="90" oninput="updateMotor(6, this.value)">
          </div>
          <div class="motor-slider">
            <label><span>S6 L3</span><span id="m7val">90&deg;</span></label>
            <input type="range" id="motor7" min="0" max="180" value="90" oninput="updateMotor(7, this.value)">
          </div>
          <div class="motor-slider">
            <label><span>S7 L4</span><span id="m8val">90&deg;</span></label>
            <input type="range" id="motor8" min="0" max="180" value="90" oninput="updateMotor(8, this.value)">
          </div>
        </div>
      </div>

      <button class="btn-close" onclick="closeMotorControl()">Close</button>
    </div>
  </div>

<script>


// Load theme on page load
document.addEventListener('DOMContentLoaded', () => {
  loadTheme();
  document.getElementById('themeColor').addEventListener('change', function() {
    const customColorInput = document.getElementById('customColor');
    if (this.value === 'custom') {
      customColorInput.style.display = 'block';
    } else {
      customColorInput.style.display = 'none';
      applyTheme(this.value);
    }
  });
  document.getElementById('customColor').addEventListener('input', function() {
    applyTheme(this.value);
  });
});

function loadTheme() {
  const savedColor = localStorage.getItem('themeColor');
  if (savedColor) {
    applyTheme(savedColor);
  }
}

function applyTheme(color) {
  const root = document.documentElement;
  root.style.setProperty('--content-color', color);
  
  // Calculate darker shades
  const rgb = hexToRgb(color);
  if (rgb) {
    const dark = `rgb(${Math.max(0, rgb.r - 20)}, ${Math.max(0, rgb.g - 20)}, ${Math.max(0, rgb.b - 20)})`;
    const darker = `rgb(${Math.max(0, rgb.r - 40)}, ${Math.max(0, rgb.g - 40)}, ${Math.max(0, rgb.b - 40)})`;
    const glow = `rgba(${rgb.r}, ${rgb.g}, ${rgb.b}, 0.3)`;
    
    root.style.setProperty('--content-color-dark', dark);
    root.style.setProperty('--content-color-darker', darker);
    root.style.setProperty('--content-color-glow', glow);
  }
}

function hexToRgb(hex) {
  const result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
  return result ? {
    r: parseInt(result[1], 16),
    g: parseInt(result[2], 16),
    b: parseInt(result[3], 16)
  } : null;
}

let driveTimer=null, driveDirection='', driveBusy=false, drivePending=null, driveAfterStop=null, activeDriveController=null, activeDriveQuery='';
// One in-flight request and one latest intent; heartbeat packets never queue.
function setDriveVisual(dir) {
  document.querySelectorAll('[data-drive]').forEach(b=>b.classList.toggle('is-held',b.dataset.drive===dir));
}
function setControlActivity(text) {
  const el=document.getElementById('controlActivity');
  if(el) el.textContent=text;
}
function driveRequest(query) {
  if (query==='heartbeat=1' && (driveBusy || drivePending || driveAfterStop)) return;
  if(query==='stop=1' && drivePending==='stop=1') {driveAfterStop=null;return;}
  if(query!=='heartbeat=1' && query!=='stop=1' && drivePending==='stop=1') {driveAfterStop=query;return;}
  if(query==='stop=1') driveAfterStop=null;
  if (query!=='heartbeat=1' && activeDriveQuery==='heartbeat=1' && activeDriveController) activeDriveController.abort();
  drivePending=query;
  pumpDrive();
}
async function pumpDrive() {
  if(driveBusy) return;
  driveBusy=true;
  while(drivePending!==null) {
    const query=drivePending; drivePending=null;
    const controller=new AbortController();
    const timeout=setTimeout(()=>controller.abort(),1200);
    activeDriveController=controller; activeDriveQuery=query;
    try {
      const r=await fetch('/cmd?'+query,{signal:controller.signal});
      if(!r.ok) throw new Error('Command rejected');
      if(query!=='heartbeat=1') {
        const el=document.getElementById('controlActivity');
        if(el) el.textContent=query.startsWith('go=')?'Movement accepted · '+query.split('=')[1].split('&')[0]:query.startsWith('pose=')?'Pose accepted · '+query.split('=')[1]:query.startsWith('stop=')?'Stop accepted · planting feet':'Servo position sent';
      }
      if(query==='heartbeat=1') {
        const state=await r.text();
        if(state==='idle') {
          clearInterval(driveTimer);driveDirection='';setDriveVisual('');
          setControlActivity('Movement ended · controller idle');
        } else if(document.getElementById('controlActivity')?.textContent.startsWith('Command delayed')) {
          setControlActivity('Connection restored · movement active');
        }
      }
    } catch(e) {
      if(driveDirection) {
        // Keep the 500 ms heartbeat alive after a transient HTTP timeout.
        // The ESP32's 3.5 s watchdog still stops movement if contact is lost.
        setControlActivity('Command delayed · retrying');
      } else {
        setControlActivity('Can’t reach Siro · check its Wi-Fi');
        clearInterval(driveTimer);driveTimer=null;setDriveVisual('');
      }
    } finally {
      clearTimeout(timeout);
      if(activeDriveController===controller) {activeDriveController=null;activeDriveQuery='';}
      if(query==='stop=1' && driveAfterStop!==null) {
        drivePending=driveAfterStop;
        driveAfterStop=null;
      }
    }
  }
  driveBusy=false;
}
function move(dir, once=false) {
  clearInterval(driveTimer); driveDirection=dir; setDriveVisual(dir);
  setControlActivity('Sending · '+(dir==='forward'?'forward':dir==='backward'?'backward':dir==='left'?'turn left':'turn right'));
  driveRequest('go='+dir+(once?'&once=1':''));
  driveTimer=setInterval(()=>{if(driveDirection) driveRequest('heartbeat=1');},500);
}
function stop() {
  clearInterval(driveTimer); driveTimer=null; driveDirection=''; setDriveVisual('');
  setControlActivity('Stop requested');
  driveRequest('stop=1');
}
window.addEventListener('blur', stop);
document.addEventListener('visibilitychange',()=>{if(document.hidden)stop();});
window.addEventListener('DOMContentLoaded',()=>{
  document.querySelectorAll('[data-drive]').forEach(b=>{
    b.style.touchAction='none';
    b.addEventListener('pointerdown',e=>{e.preventDefault();b.setPointerCapture(e.pointerId);move(b.dataset.drive);});
    ['pointerup','pointercancel'].forEach(n=>b.addEventListener(n,stop));
    b.addEventListener('lostpointercapture',()=>{if(driveDirection===b.dataset.drive) stop();});
  });
});

function pose(name) {
  clearInterval(driveTimer); driveDirection=""; setDriveVisual('');
  setControlActivity('Sending pose · '+name);
  driveRequest('pose='+name); 
}

function updateMotor(motorNum, value) {
  document.getElementById('m' + motorNum + 'val').textContent = value + '\u00B0';
  driveRequest('motor='+motorNum+'&value='+value);
}

function openSettings() {
  // Open immediately; then hydrate controls as the ESP32 replies.
  document.getElementById('settingsPanel').style.display = 'block';
  loadWifiStatus();
  fetch('/getSettings').then(r => r.json()).then(data => {
    document.getElementById('frameDelay').value = data.frameDelay || 100;
    document.getElementById('walkCycles').value = data.walkCycles || 10;
    document.getElementById('motorCurrentDelay').value = data.motorCurrentDelay || 20;
    document.getElementById('motorSpeed').value = data.motorSpeed || 'medium';
    const savedColor = localStorage.getItem('themeColor') || '#ff8c42';
    const colorSelect = document.getElementById('themeColor');
    const customColorInput = document.getElementById('customColor');
    let matchFound = false;
    for (let option of colorSelect.options) {
      if (option.value === savedColor) {
        colorSelect.value = savedColor;
        matchFound = true;
        break;
      }
    }
    if (!matchFound) {
      colorSelect.value = 'custom';
      customColorInput.value = savedColor;
      customColorInput.style.display = 'block';
    }
  }).catch(() => {
    document.getElementById('frameDelay').value = 100;
    document.getElementById('walkCycles').value = 10;
    document.getElementById('motorCurrentDelay').value = 20;
  });
}
function closeSettings() { 
  document.getElementById('settingsPanel').style.display = 'none'; 
}

function openMotorControl() {
  document.getElementById('motorControlPanel').style.display = 'block';
}

function closeMotorControl() {
  document.getElementById('motorControlPanel').style.display = 'none';
}

function saveSettings() {
  const fd = document.getElementById('frameDelay').value;
  const wc = document.getElementById('walkCycles').value;
  const mcd = document.getElementById('motorCurrentDelay').value;
  const ms = document.getElementById('motorSpeed').value;
  
  // Save theme color
  const colorSelect = document.getElementById('themeColor');
  const customColorInput = document.getElementById('customColor');
  const themeColor = colorSelect.value === 'custom' ? customColorInput.value : colorSelect.value;
  localStorage.setItem('themeColor', themeColor);
  applyTheme(themeColor);
  
  fetch(`/setSettings?frameDelay=${fd}&walkCycles=${wc}&motorCurrentDelay=${mcd}&motorSpeed=${ms}`)
    .then(() => closeSettings())
    .catch(() => closeSettings());
}

function toggleManualSsid() {
  const manual = document.getElementById('wifiManual').checked;
  document.getElementById('wifiSsidManual').style.display = manual ? 'block' : 'none';
  document.getElementById('wifiSsid').style.display = manual ? 'none' : 'block';
}

// Builds "http://<host> (<ip>)" as safe DOM nodes (no innerHTML — SSIDs/values
// are untrusted and could carry markup).
function appendRobotLink(parent, host, ip) {
  const a = document.createElement('a');
  a.href = 'http://' + host;
  a.textContent = 'http://' + host;
  a.style.color = 'var(--content-color)';
  parent.appendChild(a);
  parent.appendChild(document.createTextNode(' (' + ip + ')'));
}

// Appends "http://<host> (<ip>)" — or just the raw IP when the robot reports
// its mDNS responder didn't start — as safe DOM nodes.
function appendRobotAddress(parent, d) {
  if (d.mdns) {
    appendRobotLink(parent, d.host, d.ip);
  } else {
    parent.appendChild(document.createTextNode('http://' + d.ip));
  }
}

function loadWifiStatus() {
  fetch('/api/wifi/status').then(r => r.json()).then(d => {
    const el = document.getElementById('wifiStatus');
    el.textContent = '';
    if (d.connected) {
      el.appendChild(document.createTextNode('Connected to '));
      const b = document.createElement('b');
      b.textContent = d.ssid;            // textContent: SSID is untrusted
      el.appendChild(b);
      el.appendChild(document.createTextNode(' — '));
      appendRobotAddress(el, d);
    } else if (d.connecting) {
      el.textContent = 'Connecting…';
    } else {
      el.textContent = 'Not connected (Access Point mode only).';
    }
  }).catch(() => {
    document.getElementById('wifiStatus').textContent = 'Status unavailable.';
  });
}

// The scan runs asynchronously on the robot: /api/wifi/scan answers
// {"scanning":true} until results are ready, so poll about once a second.
function scanWifi() {
  document.getElementById('wifiResult').textContent = 'Scanning…';
  pollWifiScan(0);
}

function pollWifiScan(attempt) {
  const sel = document.getElementById('wifiSsid');
  const result = document.getElementById('wifiResult');
  fetch('/api/wifi/scan').then(r => r.json()).then(data => {
    if (!Array.isArray(data)) {
      if (attempt < 20) setTimeout(() => pollWifiScan(attempt + 1), 1000);
      else result.textContent = 'Scan timed out.';
      return;
    }
    // Map (not {}): SSIDs are untrusted and may collide with
    // Object.prototype keys ('constructor', '__proto__', ...).
    const best = new Map();
    data.forEach(n => {
      if (!n.ssid) return;
      if (!best.has(n.ssid) || n.rssi > best.get(n.ssid).rssi) best.set(n.ssid, n);
    });
    const nets = Array.from(best.values()).sort((a, b) => b.rssi - a.rssi);
    sel.textContent = '';
    const ph = document.createElement('option');
    ph.value = '';
    ph.textContent = '— select network —';
    sel.appendChild(ph);
    nets.forEach(n => {
      const pct = Math.min(100, Math.max(0, 2 * (n.rssi + 100)));
      const opt = document.createElement('option');
      opt.value = n.ssid;
      opt.textContent = n.ssid + ' (' + pct + '%' + (n.secure ? ' 🔒' : '') + ')';
      sel.appendChild(opt);
    });
    result.textContent = nets.length ? (nets.length + ' networks found.') : 'No networks found.';
  }).catch(() => {
    // Transient AP hiccup — retry on the same schedule.
    if (attempt < 20) setTimeout(() => pollWifiScan(attempt + 1), 1000);
    else result.textContent = 'Scan failed.';
  });
}

// POST starts the attempt; the robot connects in the background (its access
// point may briefly drop while it changes WiFi channel), so the outcome is
// read by polling /api/wifi/status — which also survives that brief drop.
function connectWifi() {
  const manual = document.getElementById('wifiManual').checked;
  const ssid = manual ? document.getElementById('wifiSsidManual').value.trim()
                      : document.getElementById('wifiSsid').value;
  const pass = document.getElementById('wifiPass').value;
  const result = document.getElementById('wifiResult');
  if (!ssid) { result.textContent = 'Please select or enter a network.'; return; }
  result.textContent = 'Connecting to ' + ssid + '… (can take ~15s)';
  const body = 'ssid=' + encodeURIComponent(ssid) + '&password=' + encodeURIComponent(pass);
  fetch('/api/wifi/connect', {
    method: 'POST',
    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
    body: body
  }).then(r => r.json()).then(d => {
    if (d.success) {
      setTimeout(() => pollWifiConnect(0), 1500);
    } else {
      result.textContent = 'Failed: ' + (d.error || 'could not start connection') + '.';
    }
  }).catch(() => {
    // The request may have been cut off mid-flight; the attempt is most
    // likely still running on the robot, so poll for the outcome anyway.
    setTimeout(() => pollWifiConnect(0), 1500);
  });
}

function pollWifiConnect(attempt) {
  const result = document.getElementById('wifiResult');
  fetch('/api/wifi/status').then(r => r.json()).then(d => {
    if (d.connected) {
      result.textContent = 'Connected! Reach the robot at ';
      appendRobotAddress(result, d);
      loadWifiStatus();
      return;
    }
    if (d.connecting) {
      if (attempt < 30) setTimeout(() => pollWifiConnect(attempt + 1), 1000);
      else result.textContent = 'Still trying… reopen Settings to check the status.';
      return;
    }
    result.textContent = 'Failed: ' + (d.lastError || 'could not connect') +
      '. Check the password and that it is a 2.4GHz network.';
  }).catch(() => {
    // The phone may be rejoining the robot's AP after a channel change.
    if (attempt < 30) setTimeout(() => pollWifiConnect(attempt + 1), 1000);
    else result.textContent = 'Lost contact with the robot. Rejoin its WiFi network and reopen Settings.';
  });
}

let activeGamepadIndex = null;
let gamepadPollId = null;
let lastButtonStates = [];
let lastAxisDir = { x: 0, y: 0 };
const axisThreshold = 0.5;
const pollIntervalMs = 80;

const buttonBindings = {
  0: () => pose('stand'),   // A / Cross
  1: () => pose('wave'),    // B / Circle
  2: () => pose('dance'),   // X / Square
  3: () => pose('swim'),    // Y / Triangle
  4: () => pose('point'),   // LB / L1
  5: () => pose('pushup'),  // RB / R1
  6: () => pose('bow'),     // LT / L2
  7: () => pose('shake'),   // RT / R2
  8: () => stop(),          // Back / Share
  9: () => pose('rest'),    // Start / Options
  10: () => pose('cute'),   // L3
  11: () => pose('freaky'), // R3
  12: () => move('forward'),// D-pad up
  13: () => move('backward'),// D-pad down
  14: () => move('left'),   // D-pad left
  15: () => move('right'),  // D-pad right
  16: () => stop(),         // Home / PS
  17: () => pose('worm')    // Touchpad / extra
};

const buttonReleaseStop = new Set([12, 13, 14, 15]);

function updateGamepadStatus(connected) {
  const status = document.getElementById('gamepadStatus');
  if (!status) return;
  if (connected) {
    status.textContent = 'Gamepad connected';
    status.classList.add('connected');
  } else {
    status.textContent = 'Gamepad disconnected';
    status.classList.remove('connected');
  }
}

function handleButtonChange(index, pressed) {
  if (pressed) {
    const action = buttonBindings[index];
    if (action) action();
  } else if (buttonReleaseStop.has(index)) {
    stop();
  }
}

function getAxisDirection(x, y) {
  if (Math.abs(x) < axisThreshold && Math.abs(y) < axisThreshold) return { x: 0, y: 0 };
  if (Math.abs(x) > Math.abs(y)) {
    return { x: x > 0 ? 1 : -1, y: 0 };
  }
  return { x: 0, y: y > 0 ? 1 : -1 };
}

function applyAxisDirection(dir) {
  if (dir.x === 1) move('right');
  else if (dir.x === -1) move('left');
  else if (dir.y === 1) move('backward');
  else if (dir.y === -1) move('forward');
  else stop();
}

function pollGamepad() {
  const pads = navigator.getGamepads ? navigator.getGamepads() : [];
  const pad = pads && activeGamepadIndex !== null ? pads[activeGamepadIndex] : null;
  if (!pad) {
    updateGamepadStatus(false);
    return;
  }
  updateGamepadStatus(true);

  if (!lastButtonStates.length) {
    lastButtonStates = pad.buttons.map(b => !!b.pressed);
  }
  pad.buttons.forEach((btn, i) => {
    const pressed = !!btn.pressed;
    if (pressed !== lastButtonStates[i]) {
      handleButtonChange(i, pressed);
      lastButtonStates[i] = pressed;
    }
  });

  const x = pad.axes[0] || 0;
  const y = pad.axes[1] || 0;
  const dir = getAxisDirection(x, y);
  if (dir.x !== lastAxisDir.x || dir.y !== lastAxisDir.y) {
    applyAxisDirection(dir);
    lastAxisDir = dir;
  }
}

window.addEventListener('gamepadconnected', (e) => {
  activeGamepadIndex = e.gamepad.index;
  lastButtonStates = [];
  lastAxisDir = { x: 0, y: 0 };
  updateGamepadStatus(true);
  if (!gamepadPollId) {
    gamepadPollId = setInterval(pollGamepad, pollIntervalMs);
  }
});

window.addEventListener('gamepaddisconnected', (e) => {
  if (activeGamepadIndex === e.gamepad.index) {
    activeGamepadIndex = null;
    lastButtonStates = [];
    lastAxisDir = { x: 0, y: 0 };
    updateGamepadStatus(false);
  }
});

if (navigator.getGamepads) {
  setInterval(() => {
    if (activeGamepadIndex !== null) return;
    const pads = navigator.getGamepads();
    if (!pads) return;
    for (let i = 0; i < pads.length; i++) {
      if (pads[i]) {
        activeGamepadIndex = pads[i].index;
        updateGamepadStatus(true);
        if (!gamepadPollId) {
          gamepadPollId = setInterval(pollGamepad, pollIntervalMs);
        }
        break;
      }
    }
  }, 1000);
}
</script>
</body>
</html>
)rawliteral";
