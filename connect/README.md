# connect

![](./onionmodel.png)

```
app = new Connect();
mw1 = new ConnectMW();
mw2 = new ConnectMW();
app.use(mw1);
app.use(mw2);
app.apply(req, res);
```

