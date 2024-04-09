import qrcode


qr_data = "FREE B403"
qr_image = qrcode.make(qr_data)

qr_path = qr_data + '.png'
qr_image.save('./image/' + qr_path)