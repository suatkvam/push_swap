# Push Swap

## Genel Bilgiler

- İlk argüman yığının en üstünde olmalıdır. kısaca ilk yazılan eleman top ta olmalı soldan sağa büyümeli(kağıt üzerinde)
- Program, yığının en üstünde en küçük sayı olacak şekilde sıralamak için gereken en kısa komut dizisini göstermelidir.
- Komutlar `\n` ile ayrılmalı ve başka hiçbir şey olmamalıdır.
- Amaç, yığını mümkün olan en düşük sayıda işlemle sıralamaktır.
- Değerlendirme sürecinde, programınızın bulduğu komut sayısı bir limite göre karşılaştırılacaktır. 
  - Tolere edilen maksimum işlem sayısı aşıldığında ya da sayılar düzgün sıralanmamışsa notunuz 0 olacaktır.
- Hiçbir parametre belirtilmezse, program hiçbir şey göstermemeli ve komut istemine geri dönmelidir.

## Hata Durumları

Hata durumunda, standart hataya (stderr) `"Error"` ve ardından bir `\n` yazılmalıdır.

Geçersiz durumlar:
- Bazı argümanların tamsayı olmaması
- Bazı argümanların tamsayı limitlerini aşması
- Tekrar eden rakamlar

---

## İşlemler

Amaç, rastgele olarak verilen benzersiz tamsayıları aşağıdaki kurallara göre küçükten büyüğe en az işlemle sıralamaktır.

İki yığın vardır: `a` ve `b`.

### Başlangıç Durumu

- `a` yığını rastgele sayıda benzersiz negatif ve/veya pozitif tamsayı içerir.
- `b` yığını boştur.

### Komutlar

- `sa` (swap a): `a` yığınının en üstündeki (son giren iki) elemanın yerini değiştirir. 
  - Yalnız bir eleman varsa ya da hiç eleman yoksa hiçbir şey yapmaz.
- `sb` (swap b): `b` yığınının en üstündeki (son giren iki) elemanın yerini değiştirir. 
  - Yalnız bir eleman varsa ya da hiç eleman yoksa hiçbir şey yapmaz.
- `ss`: `sa` ve `sb` işlemlerini aynı anda uygular.
- `pa` (push a): `b` yığınının en üstündeki elemanı alır ve `a` yığınının en üstüne koyar. 
  - `b` boşsa hiçbir şey yapmaz.
- `pb` (push b): `a` yığınının en üstündeki elemanı alır ve `b` yığınının en üstüne koyar. 
  - `a` boşsa hiçbir şey yapmaz.
- `ra` (rotate a): `a` yığındaki tüm elemanları bir pozisyon yukarı kaydırır. 
  - En üstteki eleman en alta geçer.
- `rb` (rotate b): `b` yığındaki tüm elemanları bir pozisyon yukarı kaydırır. 
  - En üstteki eleman en alta geçer.
- `rr`: `ra` ve `rb` işlemlerini aynı anda yapar.
- `rra` (reverse rotate a): `a` yığındaki tüm elemanları bir pozisyon aşağı kaydırır. 
  - En alttaki eleman en üste geçer.
- `rrb` (reverse rotate b): `b` yığındaki tüm elemanları bir pozisyon aşağı kaydırır. 
  - En alttaki eleman en üste geçer.
- `rrr`: `rra` ve `rrb` işlemlerini aynı anda yapar.