:root{
  --bg:#0b0b10;
  --panel:#11111a;
  --panel2:#0f0f16;
  --text:#f5f5f7;
  --muted:#b7b7c4;
  --gold:#d4af37;
  --line:rgba(255,255,255,.09);
  --shadow: 0 14px 40px rgba(0,0,0,.40);
  --radius: 18px;
}

*{box-sizing:border-box}
html,body{margin:0; padding:0}
body {
  margin: 0;
  font-family: system-ui, -apple-system, Segoe UI, Roboto, Arial, sans-serif;

  /* DARK LUXURY BACKGROUND */
  background:
    radial-gradient(1200px 600px at 20% 10%, rgba(212,175,55,0.18), transparent 60%),
    radial-gradient(900px 500px at 80% 20%, rgba(255,255,255,0.08), transparent 55%),
    linear-gradient(180deg, #0b0b10 0%, #0e0e16 50%, #0b0b10 100%);

  color: #f5f5f7;
}

a{color:inherit; text-decoration:none}
.container{max-width:1120px; margin:0 auto; padding:0 18px}
.muted{color:var(--muted)}
.small{font-size:13px}
h1,h2,h3{letter-spacing:-0.02em}
h1{font-size:44px; margin:10px 0 12px}
h2{font-size:28px; margin:0 0 10px}
h3{font-size:18px; margin:0 0 8px}

.topbar{
  border-bottom:1px solid var(--line);
  background: rgba(10,10,14,.65);
  backdrop-filter: blur(10px);
}
.topbar-inner{
  padding:10px 0;
  display:flex; justify-content:space-between; align-items:center;
  gap:10px;
}
.topbar-pill{
  border:1px solid rgba(212,175,55,.35);
  background: rgba(212,175,55,.10);
  padding:6px 10px;
  border-radius:999px;
  font-size:12px;
  color:var(--text);
}

.header{
  position:sticky; top:0; z-index:20;
  border-bottom:1px solid var(--line);
  background: rgba(10,10,14,.60);
  backdrop-filter: blur(12px);
}
.header-inner{
  display:flex; align-items:center; justify-content:space-between;
  padding:14px 0;
}
.brand{
  display:flex; align-items:center; gap:10px;
  font-weight:800;
}
.brand-mark{
  width:34px; height:34px; border-radius:12px;
  display:grid; place-items:center;
  border:1px solid rgba(212,175,55,.40);
  background: rgba(212,175,55,.12);
  color:var(--text);
  font-size:12px;
}
.brand-name{letter-spacing:.2px}

.nav{display:flex; gap:16px}
.nav a{color:var(--muted)}
.nav a:hover{color:var(--text)}

.header-actions{display:flex; gap:10px; align-items:center}
.icon-btn{
  position:relative;
  border:1px solid var(--line);
  background: rgba(255,255,255,.04);
  color:var(--text);
  border-radius:12px;
  height:36px; min-width:36px;
  padding:0 10px;
  display:flex; align-items:center; justify-content:center;
  cursor:pointer;
}
.icon-btn:hover{border-color: rgba(255,255,255,.20)}
.icon{font-size:16px}
.badge{
  position:absolute; top:-8px; right:-8px;
  background: var(--gold);
  color: #111;
  border-radius: 999px;
  font-size: 11px;
  padding: 2px 6px;
  font-weight: 800;
}

.hero{padding:44px 0 18px}
.hero-grid{
  display:grid;
  grid-template-columns: 1.35fr 0.95fr;
  gap:18px;
  align-items:stretch;
}
.kicker{
  display:inline-block;
  border:1px solid rgba(212,175,55,.35);
  background: rgba(212,175,55,.10);
  padding:7px 10px;
  border-radius:999px;
  font-size:12px;
  margin-bottom:6px;
}

.hero-cta{display:flex; gap:12px; margin-top:16px; flex-wrap:wrap}
.btn{
  border:1px solid var(--line);
  border-radius:14px;
  padding:10px 14px;
  background: rgba(255,255,255,.04);
  color:var(--text);
  cursor:pointer;
  display:inline-flex;
  align-items:center;
  justify-content:center;
  font-weight:750;
  gap:8px;
}
.btn:hover{border-color: rgba(255,255,255,.20)}
.btn.primary{
  border-color: rgba(212,175,55,.45);
  background: rgba(212,175,55,.14);
}
.btn.ghost{background: transparent}

.trust-row{
  display:grid;
  grid-template-columns: repeat(3, 1fr);
  gap:10px;
  margin-top:18px;
}
.trust{
  border:1px solid var(--line);
  background: rgba(255,255,255,.03);
  border-radius: var(--radius);
  padding:12px;
}
.trust-title{font-weight:800}
.trust-sub{color:var(--muted); font-size:13px; margin-top:4px}

.hero-card{
  border:1px solid var(--line);
  background: rgba(17,17,26,.55);
  border-radius: var(--radius);
  padding:14px;
  box-shadow: var(--shadow);
}
.hero-card-top{
  display:flex; justify-content:space-between; align-items:center; gap:12px;
  margin-bottom:10px;
}
.hero-card-title{font-weight:900}
.pill{
  border:1px solid rgba(212,175,55,.35);
  background: rgba(212,175,55,.10);
  padding:6px 10px;
  border-radius:999px;
  font-size:12px;
  width:max-content;
}
.mini-grid{
  display:grid;
  grid-template-columns: 1fr 1fr;
  gap:10px;
}
.mini{
  border:1px solid var(--line);
  background: rgba(255,255,255,.03);
  border-radius: 14px;
  padding:10px;
}
.mini-title{font-weight:800; font-size:13px}
.mini-sub{color:var(--muted); font-size:12px; margin-top:4px}
.hero-card-bottom{margin-top:10px}

.section{padding:34px 0}
.section.alt{
  border-top:1px solid var(--line);
  border-bottom:1px solid var(--line);
  background: rgba(255,255,255,.02);
}
.section-head{margin-bottom:14px}

.cards{
  display:grid;
  grid-template-columns: repeat(3, 1fr);
  gap:12px;
}
.card{
  border:1px solid var(--line);
  background: rgba(17,17,26,.45);
  border-radius: var(--radius);
  padding:16px;
}
.card-tag{
  display:inline-block;
  font-size:12px;
  color:var(--muted);
  border:1px solid var(--line);
  background: rgba(255,255,255,.03);
  padding:6px 10px;
  border-radius:999px;
  margin-bottom:10px;
}

.toolbar{
  display:flex;
  gap:12px;
  align-items:center;
  justify-content:space-between;
  flex-wrap:wrap;
  margin: 14px 0 10px;
}
.searchbox{
  flex:1;
  min-width: 260px;
  display:flex; align-items:center; gap:10px;
  border:1px solid var(--line);
  background: rgba(0,0,0,.22);
  border-radius: 14px;
  padding: 10px 12px;
}
.searchbox input{
  width:100%;
  border:none;
  outline:none;
  background:transparent;
  color:var(--text);
  font-size:14px;
}
.filters{display:flex; gap:10px; flex-wrap:wrap}
select{
  border:1px solid var(--line);
  background: rgba(255,255,255,.03);
  color:var(--text);
  border-radius: 14px;
  padding:10px 12px;
  outline:none;
}

.grid{
  display:grid;
  grid-template-columns: repeat(3, 1fr);
  gap:12px;
  margin-top:14px;
}
.product{
  border:1px solid var(--line);
  background: rgba(17,17,26,.45);
  border-radius: var(--radius);
  overflow:hidden;
  transition: transform .12s ease, border-color .12s ease;
}
.product:hover{
  transform: translateY(-2px);
  border-color: rgba(255,255,255,.18);
}
.pimg{
  height:170px;
  background:
    radial-gradient(500px 220px at 30% 10%, rgba(212,175,55,.18), transparent 60%),
    linear-gradient(180deg, rgba(255,255,255,.06), rgba(255,255,255,.02));
  display:flex; align-items:center; justify-content:center;
  color: rgba(255,255,255,.28);
  font-weight:800;
  position:relative;
}
.pimg img{
  width:100%; height:100%;
  object-fit: cover;
  display:block;
}
.pbody{padding:14px}
.ptop{
  display:flex; justify-content:space-between; align-items:flex-start; gap:10px;
}
.pname{font-weight:900}
.pprice{font-weight:900; color: var(--gold)}
.pmeta{margin-top:8px; display:flex; gap:8px; flex-wrap:wrap}
.tag{
  font-size:12px;
  color:var(--muted);
  border:1px solid var(--line);
  background: rgba(255,255,255,.03);
  padding:6px 10px;
  border-radius:999px;
}
.pactions{
  display:flex; gap:10px; margin-top:12px;
}
.pactions .btn{flex:1}

.two-col{
  display:grid;
  grid-template-columns: 1fr 1fr;
  gap:12px;
}
.panel{
  border:1px solid var(--line);
  background: rgba(17,17,26,.45);
  border-radius: var(--radius);
  padding:16px;
}
.chip-row{display:flex; gap:8px; flex-wrap:wrap; margin-top:12px}
.chip{
  border:1px solid rgba(212,175,55,.28);
  background: rgba(212,175,55,.08);
  padding:6px 10px;
  border-radius:999px;
  font-size:12px;
}

.list{margin:0; padding-left:18px}
.list li{margin:8px 0}

.form{
  border:1px solid var(--line);
  background: rgba(17,17,26,.45);
  border-radius: var(--radius);
  padding:16px;
  max-width: 860px;
}
.form-row{
  display:grid;
  grid-template-columns: 1fr 1fr;
  gap:12px;
}
label{display:grid; gap:6px; color:var(--muted); font-size:14px}
input, textarea{
  border:1px solid var(--line);
  background: rgba(0,0,0,.22);
  color:var(--text);
  border-radius: 14px;
  padding:10px 12px;
  outline:none;
}
textarea{min-height: 120px; resize: vertical}

.footer{
  border-top:1px solid var(--line);
  padding:20px 0;
  background: rgba(10,10,14,.55);
}
.footer-inner{
  display:flex; justify-content:space-between; align-items:flex-start;
  gap:12px; flex-wrap:wrap;
}
.footer-brand{font-weight:900}
.footnote{
  margin-top: 14px;
  color: var(--muted);
  font-size: 13px;
}

.modal, .drawer{display:none}
.modal.open, .drawer.open{display:block}
.modal-backdrop, .drawer-backdrop{
  position:fixed; inset:0;
  background: rgba(0,0,0,.55);
}
.modal-card{
  position:fixed;
  inset:auto;
  left:50%;
  top:50%;
  transform: translate(-50%,-50%);
  width:min(920px, calc(100% - 28px));
  border:1px solid var(--line);
  background: rgba(17,17,26,.85);
  border-radius: var(--radius);
  box-shadow: var(--shadow);
  padding:14px;
}
.modal-close{
  position:absolute; top:10px; right:12px;
  border:none;
  background: transparent;
  color: var(--text);
  font-size: 26px;
  cursor:pointer;
}
.modal-grid{
  display:grid;
  grid-template-columns: 1.05fr 0.95fr;
  gap:12px;
  align-items:stretch;
}
.modal-img{
  height:320px;
  border-radius: 16px;
  border:1px solid var(--line);
  background:
    radial-gradient(600px 280px at 30% 10%, rgba(212,175,55,.18), transparent 60%),
    linear-gradient(180deg, rgba(255,255,255,.06), rgba(255,255,255,.02));
  display:flex; align-items:center; justify-content:center;
  color: rgba(255,255,255,.28);
  overflow:hidden;
}
.modal-img img{width:100%; height:100%; object-fit:cover; display:block}
.modal-title{margin-top:10px}
.modal-price{margin-top:8px; font-weight:900; color:var(--gold); font-size:18px}
.modal-actions{display:flex; gap:10px; margin-top:14px; flex-wrap:wrap}

.drawer-panel{
  position:fixed;
  right:0; top:0; bottom:0;
  width:min(420px, calc(100% - 38px));
  border-left:1px solid var(--line);
  background: rgba(17,17,26,.92);
  box-shadow: var(--shadow);
  padding:14px;
}
.drawer-head{display:flex; justify-content:space-between; align-items:center; gap:10px}
.drawer-title{font-weight:900}
.drawer-body{margin-top:12px; display:grid; gap:10px; max-height: calc(100vh - 140px); overflow:auto}
.wish-item{
  border:1px solid var(--line);
  background: rgba(255,255,255,.03);
  border-radius: 14px;
  padding:12px;
  display:flex; justify-content:space-between; gap:12px;
}
.drawer-foot{margin-top:12px; padding-top:12px; border-top:1px solid var(--line)}

@media (max-width: 920px){
  .hero-grid{grid-template-columns:1fr}
  .grid{grid-template-columns:1fr}
  .cards{grid-template-columns:1fr}
  .two-col{grid-template-columns:1fr}
  .modal-grid{grid-template-columns:1fr}
  .form-row{grid-template-columns:1fr}
  h1{font-size:34px}
  .nav{display:none}
}
