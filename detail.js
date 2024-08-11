document.addEventListener('DOMContentLoaded', () => {
    const items = [
        { id: 1, name: '충전기', image: 'images/charger.jpg', quantity: 10, rentalPeriod: '2024-07-20' },
        { id: 2, name: '공학용 계산기', image: 'images/calculator.jpg', quantity: 5, rentalPeriod: '2024-07-22' },
        { id: 3, name: '돗자리', image: 'images/mat.jpg', quantity: 8, rentalPeriod: '2024-07-25' },
        { id: 4, name: '고데기', image: 'images/hair_straightener.jpg', quantity: 2, rentalPeriod: '2024-07-26' },
        { id: 5, name: '담요', image: 'images/blanket.jpg', quantity: 15, rentalPeriod: '2024-07-28' },
        { id: 6, name: '우산', image: 'images/umbrella.jpg', quantity: 20, rentalPeriod: '2024-07-30' }
    ];

    function getItemIdFromUrl() {
        const params = new URLSearchParams(window.location.search);
        return parseInt(params.get('id'));
    }

    const itemId = getItemIdFromUrl();
    const item = items.find(i => i.id === itemId);

    if (item) {
        document.getElementById('item-name').textContent = item.name;
        document.getElementById('item-image').src = item.image;
        document.getElementById('item-image').alt = item.name;
        document.getElementById('item-quantity').textContent = item.quantity;
        document.getElementById('item-rental-period').textContent = item.rentalPeriod;
    } else {
        alert('물품을 찾을 수 없습니다.');
    }
});
