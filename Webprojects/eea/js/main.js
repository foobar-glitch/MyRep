// Fügen Sie Ihren Code hier ein.

function pos(zahl, mod) {
    if (zahl < 0) {
        zahl = pos(zahl + mod, mod);
    }
    return zahl;
}


function euklid(zahl, modulus) {
    var q = [modulus, zahl]
    var r = [0,0]
    var t = [0, 1]
    var i = 2
    while (true) {
        q.push(q[i - 2] % q[i - 1])
        r.push(Math.floor(q[i-2]/q[i-1]))
        t.push(t[i - 2] - t[i - 1] * r[i])
        console.log("r="+r[i]+" t="+t[i])
        if (q[i] === 1) {
            return t[i] % modulus
        }
        else if (q[i] === 0) {
			alert("gcd not equals 1")
            throw new DivisionException("Falsche Zahlen")
        }
        i++
    }
}


const res = document.querySelector('.result')
const numbers = document.getElementsByTagName('input')
const button = document.querySelector('.keys')



button.addEventListener('click', e => {
    if (e.target.matches("button")) {
        const action = e.target.dataset.action
        var result = 0
        var zahl = numbers[0].value
        var modulus = numbers[1].value
        if (action == "eea") {
            result = euklid(zahl, modulus)
        }
        res.textContent = result
    }
})

