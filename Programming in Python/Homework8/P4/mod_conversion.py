def in2cm_table(s, e, g):    
    fm = "{0:>5.1f}{1:>7.1f}"
    print("{0:>5}{1:>7}".format("inch","cm"))
    i=s
    while(i<=e):
        conv=i*2.54
        print(fm.format(i,conv))
        i+=g
    return

def in2cm_table_html(s,e,g):
    f=open("in2cm.html","w")
    html_code='''
    <html>
    <table>
    <tr>
        <th>{0:5}</th><th>{1:>7}</th>
    </tr>
    '''.format("inch","cm")
    fm = "{0:>5.1f}{1:>7.1f}"
    #f.write(html_code.format("inch","cm"))
    i=s
    while(i<=e):
        conv=i*2.54
        html_code+='''
        <tr>
            <td>{0:5.1f}</td><td>{1:>7.1f}</td>
        </tr>
        '''.format(i,conv)
        i+=g
    html_code+='''
    </table>
    </html>
    '''
    f.write(html_code)
    return