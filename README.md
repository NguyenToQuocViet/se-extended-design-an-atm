# ATM OOP - CO3001 Software Engineering (Honor Program)

He thong ATM don gian viet bang C++20, mo phong qua giao dien dong lenh (CLI).

## Build & Run

```bash
make        # Compile
make run    # Compile + chay
make clean  # Xoa build/
```

Yeu cau: g++ >= 12, GNU Make.

## Cau truc thu muc

```
src/
  common/   - Money (xu ly tien te, tranh loi float)
  bank/     - Card, Account, Customer, Bank
  atm/      - ATM (session loop + cac giao dich)
  main.cpp  - Seed data + entry point
```

## Thiet ke OOP

| Class | Mo ta |
|-------|-------|
| `Money` | Luu tru tien bang cents (int64), tranh loi lam tron float |
| `Card` | So the, han su dung |
| `Account` | Abstract base: `deposit`, `withdraw` la pure virtual |
| `CheckingAccount` | Tai khoan thanh toan, ke thua `Account` |
| `SavingAccount` | Tai khoan tiet kiem, ke thua `Account` |
| `Customer` | Ten, PIN, so huu `Card` va `Account*` |
| `Bank` | Danh sach khach hang, xac thuc PIN |
| `ATM` | Quan ly phien lam viec, goi giao dich |

## Chuc nang

- Xac thuc bang so the + PIN
- Xem so du
- Rut tien
- Nap tien
- Chuyen khoan sang tai khoan khac

## Tai khoan demo

| Ten | So the | PIN | So du |
|-----|--------|-----|-------|
| Quoc Viet | 2610-2005 | 261005 | $10000.00 |
| Phuong Yen | 0401-2006 | 200600 | $500.00 |
| Quoc Vu | 1703-2026 | 1111 | $5.00 |
