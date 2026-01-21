const products = [
  { id: 1, name: "Luna Glow Ring", category: "Rings", price: 14.99, tags: ["Best Seller", "Minimal"], featured: true, newest: 4, img: "ring.jpg" , desc:"Glossy finish with a crystal-inspired centerpiece. Lightweight and comfortable for daily wear."},
  { id: 2, name: "Velvet Halo Ring", category: "Rings", price: 16.50, tags: ["Premium Look"], featured: true, newest: 3, img: "", desc:"Rounded halo design that looks premium while staying affordable and lightweight."},
  { id: 3, name: "Crystal Bloom Necklace", category: "Necklaces", price: 19.99, tags: ["Signature"], featured: true, newest: 5, img: "Necklace.jpg", desc:"Delicate pendant with a floral sparkle design — perfect for gifting or events."},
  { id: 4, name: "Moonlight Grace Necklace", category: "Necklaces", price: 18.25, tags: ["Minimal"], featured: false, newest: 2, img: "", desc:"A clean, elegant chain designed to elevate everyday outfits."},
  { id: 5, name: "Aurora Stud Earrings", category: "Earrings", price: 11.99, tags: ["Best Seller"], featured: true, newest: 6, img: "Earrings", desc:"Minimal studs with a bright finish — everyday style that matches everything."},
  { id: 6, name: "Crystal Cascade Drops", category: "Earrings", price: 15.75, tags: ["Occasion"], featured: false, newest: 1, img: "", desc:"Drop earrings designed for events with a refined sparkle look."},
  { id: 7, name: "Infinity Glow Bangle", category: "Bracelets", price: 17.99, tags: ["Classic"], featured: true, newest: 7, img: "", desc:"Classic bangle silhouette with modern shine — pairs well with watches."},
  { id: 8, name: "Golden Thread Bracelet", category: "Bracelets", price: 13.49, tags: ["Minimal"], featured: false, newest: 8, img: "", desc:"Chain bracelet style with elegant detail and a soft gold-inspired finish."},
  { id: 9, name: "Aurora Luxe Set", category: "Sets", price: 29.99, tags: ["Gift Set"], featured: true, newest: 9, img: "", desc:"Coordinated set for a polished look — designed for gifting and events."},
];

const els = {
  grid: document.getElementById("productGrid"),
  featuredMiniGrid: document.getElementById("featuredMiniGrid"),
  search: document.getElementById("searchInput"),
  category: document.getElementById("categorySelect"),
  sort: document.getElementById("sortSelect"),
  clear: document.getElementById("clearBtn"),

  modal: document.getElementById("modal"),
  modalBackdrop: document.getElementById("modalBackdrop"),
  modalClose: document.getElementById("modalClose"),
  closeBtn2: document.getElementById("closeBtn2"),
  modalImg: document.getElementById("modalImg"),
  modalTitle: document.getElementById("modalTitle"),
  modalCategory: document.getElementById("modalCategory"),
  modalPrice: document.getElementById("modalPrice"),
  modalDesc: document.getElementById("modalDesc"),
  wishBtn: document.getElementById("wishBtn"),

  openWishlist: document.getElementById("openWishlist"),
  drawer: document.getElementById("drawer"),
  drawerBackdrop: document.getElementById("drawerBackdrop"),
  drawerClose: document.getElementById("drawerClose"),
  wishList: document.getElementById("wishList"),
  wishCount: document.getElementById("wishCount"),
};

let activeProduct = null;
let wishlist = JSON.parse(localStorage.getItem("mg_wishlist") || "[]");

function money(n){ return `$${n.toFixed(2)}`; }

function productImageHTML(p){
  // If you later add images: set p.img to "images/filename.jpg"
  // For now, shows a classy placeholder.
  if (p.img) return `<img src="${p.img}" alt="${p.name}">`;
  return `<div class="phText">MOONLIGHT GEMS</div>`;
}

function cardTemplate(p){
  return `
    <article class="product">
      <div class="pimg" data-qv="${p.id}">
        ${productImageHTML(p)}
      </div>
      <div class="pbody">
        <div class="ptop">
          <div>
            <div class="pname">${p.name}</div>
            <div class="muted small">${p.category}</div>
          </div>
          <div class="pprice">${money(p.price)}</div>
        </div>

        <div class="pmeta">
          ${p.tags.map(t => `<span class="tag">${t}</span>`).join("")}
        </div>

        <div class="pactions">
          <button class="btn primary" data-qv="${p.id}">Quick View</button>
          <button class="btn ghost" data-wish="${p.id}">♡</button>
        </div>
      </div>
    </article>
  `;
}

function miniTemplate(p){
  return `
    <div class="mini" role="button" tabindex="0" data-qv="${p.id}">
      <div class="mini-title">${p.name}</div>
      <div class="mini-sub">${p.category} • ${money(p.price)}</div>
    </div>
  `;
}

function applyFilters(list){
  const q = (els.search.value || "").trim().toLowerCase();
  const cat = els.category.value;

  let out = list.filter(p => {
    const matchesQ = !q || (p.name.toLowerCase().includes(q) || p.category.toLowerCase().includes(q) || p.tags.join(" ").toLowerCase().includes(q));
    const matchesCat = (cat === "all") || (p.category === cat);
    return matchesQ && matchesCat;
  });

  const sort = els.sort.value;
  if (sort === "price_low") out.sort((a,b)=>a.price-b.price);
  else if (sort === "price_high") out.sort((a,b)=>b.price-a.price);
  else if (sort === "newest") out.sort((a,b)=>b.newest-a.newest);
  else out.sort((a,b)=> (b.featured - a.featured) || (b.newest - a.newest));

  return out;
}

function render(){
  const filtered = applyFilters(products);
  els.grid.innerHTML = filtered.map(cardTemplate).join("");
  wireCardActions();
  renderFeatured();
  renderWishlistCount();
}

function renderFeatured(){
  const featured = products.filter(p=>p.featured).slice(0,4);
  els.featuredMiniGrid.innerHTML = featured.map(miniTemplate).join("");
  // mini click
  els.featuredMiniGrid.querySelectorAll("[data-qv]").forEach(el=>{
    el.addEventListener("click", ()=> openModal(Number(el.dataset.qv)));
    el.addEventListener("keydown", (e)=>{ if(e.key==="Enter") openModal(Number(el.dataset.qv)); });
  });
}

function wireCardActions(){
  document.querySelectorAll("[data-qv]").forEach(btn=>{
    btn.addEventListener("click", ()=> openModal(Number(btn.dataset.qv)));
  });
  document.querySelectorAll("[data-wish]").forEach(btn=>{
    btn.addEventListener("click", ()=> toggleWish(Number(btn.dataset.wish)));
  });
}

function openModal(id){
  const p = products.find(x=>x.id===id);
  if(!p) return;
  activeProduct = p;

  els.modalTitle.textContent = p.name;
  els.modalCategory.textContent = p.category;
  els.modalPrice.textContent = money(p.price);
  els.modalDesc.textContent = p.desc;

  if (p.img){
    els.modalImg.innerHTML = `<img src="${p.img}" alt="${p.name}">`;
  } else {
    els.modalImg.textContent = "Image";
  }

  const inWish = wishlist.includes(p.id);
  els.wishBtn.textContent = inWish ? "♡ Remove from Wishlist" : "♡ Add to Wishlist";

  els.modal.classList.add("open");
  els.modal.setAttribute("aria-hidden","false");
}

function closeModal(){
  els.modal.classList.remove("open");
  els.modal.setAttribute("aria-hidden","true");
  activeProduct = null;
}

function toggleWish(id){
  if (wishlist.includes(id)) wishlist = wishlist.filter(x=>x!==id);
  else wishlist.push(id);

  localStorage.setItem("mg_wishlist", JSON.stringify(wishlist));
  renderWishlistCount();
  renderWishlistDrawer();

  if(activeProduct && activeProduct.id===id){
    const inWish = wishlist.includes(id);
    els.wishBtn.textContent = inWish ? "♡ Remove from Wishlist" : "♡ Add to Wishlist";
  }
}

function renderWishlistCount(){
  els.wishCount.textContent = String(wishlist.length);
}

function openDrawer(){
  renderWishlistDrawer();
  els.drawer.classList.add("open");
  els.drawer.setAttribute("aria-hidden","false");
}

function closeDrawer(){
  els.drawer.classList.remove("open");
  els.drawer.setAttribute("aria-hidden","true");
}

function renderWishlistDrawer(){
  if(!wishlist.length){
    els.wishList.innerHTML = `<div class="muted small">No items saved yet. Click ♡ on any product.</div>`;
    return;
  }
  const items = products.filter(p=>wishlist.includes(p.id));
  els.wishList.innerHTML = items.map(p=>`
    <div class="wish-item">
      <div>
        <div style="font-weight:900">${p.name}</div>
        <div class="muted small">${p.category} • ${money(p.price)}</div>
      </div>
      <button class="btn ghost" data-remove="${p.id}">Remove</button>
    </div>
  `).join("");

  els.wishList.querySelectorAll("[data-remove]").forEach(btn=>{
    btn.addEventListener("click", ()=> toggleWish(Number(btn.dataset.remove)));
  });
}

function clearAll(){
  els.search.value = "";
  els.category.value = "all";
  els.sort.value = "featured";
  render();
}

/* Events */
els.search.addEventListener("input", render);
els.category.addEventListener("change", render);
els.sort.addEventListener("change", render);
els.clear.addEventListener("click", clearAll);

els.modalBackdrop.addEventListener("click", closeModal);
els.modalClose.addEventListener("click", closeModal);
els.closeBtn2.addEventListener("click", closeModal);

els.wishBtn.addEventListener("click", ()=>{
  if(activeProduct) toggleWish(activeProduct.id);
});

els.openWishlist.addEventListener("click", openDrawer);
els.drawerBackdrop.addEventListener("click", closeDrawer);
els.drawerClose.addEventListener("click", closeDrawer);

document.addEventListener("keydown", (e)=>{
  if(e.key==="Escape"){
    closeModal();
    closeDrawer();
  }
});

/* Initial render */
renderWishlistCount();
render();
