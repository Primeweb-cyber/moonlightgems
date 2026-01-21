:root{
  --bg:#0b0b0f;
  --card:#11111a;
  --text:#f5f5f7;
  --muted:#b7b7c2;
  --gold:#d4af37;
  --line:rgba(255,255,255,0.08);
}

*{box-sizing:border-box}
body{
  margin:0;
  font-family: system-ui, -apple-system, Segoe UI, Roboto, Arial, sans-serif;
  background: linear-gradient(180deg, #0b0b0f 0%, #0e0e16 60%, #0b0b0f 100%);
  color:var(--text);
}

a{color:inherit; text-decoration:none}
.container{max-width:1100px; margin:0 auto; padding:0 18px}

.header{
  position:sticky; top:0; z-index:10;
  backdrop-filter: blur(10px);
  background: rgba(10,10,15,0.65);
  border-bottom: 1px solid var(--line);
}

.nav{
  display:flex; align-items:center; justify-content:space-between;
  padding:14px 0;
}
.brand{
  font-weight:800; letter-spacing:0.3px;
  color:var(--text);
}
.menu a{
  margin-left:16px;
  color:var(--muted);
}
.menu a:hover{color:var(--text)}

.hero{padding:54px 0 26px}
.hero-grid{
  display:grid;
  grid-template-columns: 1.4fr 0.9fr;
  gap:22px;
  align-items:stretch;
}

h1{font-size:44px; margin:0 0 10px}
h2{font-size:28px; margin:0 0 14px}
h3{margin:0 0 8px}
.subtext{color:var(--muted); line-height:1.6}
.note{color:var(--muted); margin-top:14px; font-size:13px}

.cta-row{display:flex; gap:12px; margin-top:18px; flex-wrap:wrap}
.btn{
  display:inline-block;
  border:1px solid rgba(212,175,55,0.35);
  background: rgba(212,175,55,0.14);
  color:var(--text);
  padding:10px 14px;
  border-radius:12px;
  font-weight:650;
}
.btn:hover{border-color: rgba(212,175,55,0.6)}
.btn-outline{
  background:transparent;
  border:1px solid var(--line);
  color:var(--text);
}
.btn-outline:hover{border-color: rgba(255,255,255,0.22)}

.hero-card{
  border:1px solid var(--line);
  background: rgba(17,17,26,0.7);
  border-radius:18px;
  padding:18px;
  position:relative;
  overflow:hidden;
}
.badge{
  position:absolute; right:14px; top:14px;
  font-size:12px;
  color:var(--bg);
  background:var(--gold);
  padding:6px 10px;
  border-radius:999px;
  font-weight:750;
}
.mini-list{margin:10px 0 0; padding-left:18px; color:var(--muted)}
.mini-list li{margin:8px 0}

.section{padding:34px 0}
.section.alt{
  background: rgba(255,255,255,0.03);
  border-top:1px solid var(--line);
  border-bottom:1px solid var(--line);
}

.cards{
  display:grid;
  grid-template-columns: repeat(3, 1fr);
  gap:14px;
}
.card{
  border:1px solid var(--line);
  background: rgba(17,17,26,0.55);
  border-radius:16px;
  padding:16px;
  color:var(--muted);
}
.card h3{color:var(--text)}

.grid{
  display:grid;
  grid-template-columns: repeat(3, 1fr);
  gap:14px;
  margin-top:16px;
}
.product{
  border:1px solid var(--line);
  background: rgba(17,17,26,0.55);
  border-radius:16px;
  padding:14px;
}
.ph{
  height:150px;
  border-radius:12px;
  border:1px dashed rgba(255,255,255,0.18);
  display:flex;
  align-items:center;
  justify-content:center;
  color:rgba(255,255,255,0.35);
  margin-bottom:12px;
}
.pname{font-weight:750}
.pdesc{color:var(--muted); margin-top:6px; line-height:1.5; font-size:14px}

.form{
  max-width:520px;
  display:grid;
  gap:12px;
  margin-top:14px;
}
label{display:grid; gap:6px; color:var(--muted); font-size:14px}
input, textarea{
  width:100%;
  padding:10px 12px;
  border-radius:12px;
  border:1px solid var(--line);
  background: rgba(0,0,0,0.25);
  color:var(--text);
  outline:none;
}
textarea{min-height:120px; resize:vertical}

.footer{
  padding:22px 0;
  color:var(--muted);
  border-top:1px solid var(--line);
}
.footnote{margin-top:6px; font-size:13px}

@media (max-width: 900px){
  .hero-grid{grid-template-columns:1fr}
  .cards{grid-template-columns:1fr}
  .grid{grid-template-columns:1fr}
  h1{font-size:34px}
  .menu{display:none}
}
