document.addEventListener('DOMContentLoaded', () => {
    const decreaseButtons = document.querySelectorAll('.decrease');
    const increaseButtons = document.querySelectorAll('.increase');

    decreaseButtons.forEach(button => {
        button.addEventListener('click', () => {
            const itemId = button.dataset.itemId;
            const quantitySpan = button.parentNode.querySelector('.quantity');
            let currentQuantity = parseInt(quantitySpan.textContent);

            if (currentQuantity > 0) {
                currentQuantity--;
                quantitySpan.textContent = currentQuantity;

                // AJAX 요청 보내기 (수량 감소)
                fetch(`/decrease_quantity/${itemId}`, { method: 'POST' })
                    .then(response => response.json())
                    .then(data => {
                        if (!data.success) {
                            alert(data.message || '수량 변경에 실패했습니다.');
                            currentQuantity++; // 변경 실패 시 원래 수량으로 복원
                            quantitySpan.textContent = currentQuantity;
                        }
                    })
                    .catch(error => {
                        console.error('Error:', error);
                        alert('수량 변경 중 오류가 발생했습니다.');
                        currentQuantity++; // 변경 실패 시 원래 수량으로 복원
                        quantitySpan.textContent = currentQuantity;
                    });
            }
        });
    });

    increaseButtons.forEach(button => {
        button.addEventListener('click', () => {
            const itemId = button.dataset.itemId;
            const quantitySpan = button.parentNode.querySelector('.quantity');
            let currentQuantity = parseInt(quantitySpan.textContent);

            currentQuantity++;
            quantitySpan.textContent = currentQuantity;

            // AJAX 요청 보내기 (수량 증가)
            fetch(`/increase_quantity/${itemId}`, { method: 'POST' })
                .then(response => response.json())
                .then(data => {
                    if (!data.success) {
                        alert(data.message || '수량 변경에 실패했습니다.');
                        currentQuantity--; // 변경 실패 시 원래 수량으로 복원
                        quantitySpan.textContent = currentQuantity;
                    }
                })
                .catch(error => {
                    console.error('Error:', error);
                    alert('수량 변경 중 오류가 발생했습니다.');
                    currentQuantity--; // 변경 실패 시 원래 수량으로 복원
                    quantitySpan.textContent = currentQuantity;
                });
        });
    });
});