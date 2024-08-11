document.addEventListener('DOMContentLoaded', () => {
    const items = [
        { id: 1, name: '충전기', image: 'images/charger.jpg' },
        { id: 2, name: '공학용 계산기', image: 'images/calculator.jpg' },
        { id: 3, name: '돗자리', image: 'images/mat.jpg' },
        { id: 4, name: '고데기', image: 'images/hair_straightener.jpg' },
        { id: 5, name: '담요', image: 'images/blanket.jpg' },
        { id: 6, name: '우산', image: 'images/umbrella.jpg' }
    ];

    const itemGallery = document.getElementById('item-gallery');
    
    items.forEach(item => {
        const itemDiv = document.createElement('div');
        itemDiv.className = 'item';
        
        const itemImage = document.createElement('img');
        itemImage.src = item.image;
        itemImage.alt = item.name;
        itemImage.addEventListener('click', () => {
            window.location.href = `detail.html?id=${item.id}`;
        });
        
        const itemName = document.createElement('p');
        itemName.textContent = item.name;
        
        itemDiv.appendChild(itemImage);
        itemDiv.appendChild(itemName);
        itemGallery.appendChild(itemDiv);
    });
});
