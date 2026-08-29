const container = document.getElementById("container")
const loader = document.getElementById("load-block")



const applyButton = document.getElementById("apply-btn");

applyButton.addEventListener("click", async () => {
    const wifiSsid = document.getElementById("ssid").value;
    const wifiPassword = document.getElementById("password").value;
    const activationCode = document.getElementById("activation-code").value;

    if (!wifiSsid || !wifiPassword || !activationCode) {
        alert("Not find all data");
        return;
    }

    const data = {
        "ssid": wifiSsid,
        "password": wifiPassword,
        "token": activationCode
    };
    
    console.log(data);

    fetch("/click", { 
        method: "POST",
        body: new URLSearchParams(data)
    });

    container.style.display = "none";
    loader.style.display = "flex";
});
